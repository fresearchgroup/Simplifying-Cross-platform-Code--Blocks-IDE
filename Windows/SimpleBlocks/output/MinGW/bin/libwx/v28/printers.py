###############################################################################
# Name:         printers.py
# Purpose:      pretty-printers for wx data structures: this file is meant to
#               be sourced from gdb using "source -p" (or, better, autoloaded
#               in the future...)
# Author:       Vadim Zeitlin
# Created:      2009-01-04
# Update:       2010-06-15
# RCS-Id:       $Id:$
# Copyright:    (c) 2009 Vadim Zeitlin 2010 Ollydbg Loaden
# License:      wxWindows licence
###############################################################################

# Define wxFooPrinter class implementing (at least) to_string() method for each
# wxFoo class we want to pretty print. Then just add wxFoo to the types array
# in wxLookupFunction at the bottom of this file.


#modify by ttch 20100623

import sys
import gdb
import itertools
import re


class static:
    "Creates a 'static' method"
    def __init__(self, function):
        self.__call__ = function

wx_pretty_printers = []

def register_pretty_printer(pretty_printer):
    "Registers a Pretty Printer"
    wx_pretty_printers.append(pretty_printer)
    return pretty_printer

# shamelessly stolen from std::string example
@register_pretty_printer
class wxStringPrinter:
    
    regex = re.compile('^wxString$$');
    @static
    def supports(typename):
        return wxStringPrinter.regex.search(typename)
    @static
    def is_undefine(val):
        try:
            val['m_pchData'].string()
            return True
        except:
            return False

    def __init__(self, val):
        self.val = val

    def to_string(self):
        return self.val['m_pchData'].string()

    def display_hint(self):
        return 'string'

@register_pretty_printer
class wxXYPrinterBase:
    regex = re.compile('^wxXY$');
    @static
    def supports(typename):
        return wxRectPrinter.regex.search(typename)
    @static
    def is_undefine(val):
    	return False
    def __init__(self, val):
        self.x = val['x']
        self.y = val['y']

@register_pretty_printer
class wxPointPrinter(wxXYPrinterBase):
    regex = re.compile('^wxPoint$');
    @static
    def supports(typename):
        return wxRectPrinter.regex.search(typename)
    @static
    def is_undefine(val):
    	return False
    def to_string(self):
        return '(%d, %d)' % (self.x, self.y)

@register_pretty_printer
class wxSizePrinter(wxXYPrinterBase):
    regex = re.compile('^wxSize$');
    @static
    def supports(typename):
        return wxRectPrinter.regex.search(typename)
    @static
    def is_undefine(val):
    	return False
    def to_string(self):
        return '%d*%d' % (self.x, self.y)


@register_pretty_printer
class wxRectPrinter(wxXYPrinterBase):
    regex = re.compile('^wxRect$');
    @static
    def supports(typename):
        return wxRectPrinter.regex.search(typename)
    @static
    def is_undefine(val):
    	return True
    def __init__(self, val):
        wxXYPrinterBase.__init__(self, val)
        self.width = val['width']
        self.height = val['height']

    def to_string(self):
        return '(%d, %d) %d*%d' % (self.x, self.y, self.width, self.height)

# support wxArrayString
@register_pretty_printer
class wxArrayStringPrinter:
    regex = re.compile('^wxArrayString$');
    @static
    def supports(typename):
        return wxArrayStringPrinter.regex.search(typename)

    @static
    def is_undefine(val):
        if val['m_nCount'] > 1000000:
            return False
        else:
            return True

    class _iterator:
        def __init__(self, val, max):
            self.val = val
            self.count = 0
            self.max = max

        def __iter__(self):
            return self

        def next(self):
            if self.count == self.max:
                raise StopIteration
            count = self.count
            self.count = self.count + 1
            return ('[%d]' % count, self.val['m_pItems'][count])


    def __init__(self, val):
        self.val = val


    def to_string(self):
    	try:
        	return "%s count of wxArrayString" % (self.val['m_nCount'])
       	except:
       		return None
    def children (self):
    	try:
    		return self._iterator( self.val,self.val['m_nCount'])
    	except:
    		return None


def register_libwx_printers (obj):
    if obj == None:
        obj = gdb
    obj.pretty_printers.append (lookup_function)
    

# The function looking up the pretty-printer to use for the given value.
def lookup_function(val):
    # Get the type.
    type = val.type

    # If it points to a reference, get the reference.
    if type.code == gdb.TYPE_CODE_REF:
        type = type.target ()

    # Get the unqualified type, stripped of typedefs.
    type = type.unqualified ().strip_typedefs ()

    typename = type.tag
    if typename == None:
        return None

    for pretty_printer in wx_pretty_printers:
        if pretty_printer.supports(typename):
            if pretty_printer.is_undefine(val):
                return pretty_printer(val)

    return None