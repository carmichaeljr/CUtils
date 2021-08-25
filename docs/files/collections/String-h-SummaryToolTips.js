﻿NDSummary.OnToolTipsLoaded("File:collections/String.h",{38:"<div class=\"NDToolTip TClass LC\"><div class=\"NDClassPrototype\" id=\"NDClassPrototype38\"><div class=\"CPEntry TClass Current\"><div class=\"CPModifiers\"><span class=\"SHKeyword\">typedef</span> <span class=\"SHKeyword\">struct</span></div><div class=\"CPName\">String</div></div></div><div class=\"TTSummary\">The struct that represents a String.&nbsp; This class is for storing and manipulating Strings.&nbsp; General usage is as follows:</div></div>",40:"<div class=\"NDToolTip TVariable LC\"><div id=\"NDPrototype40\" class=\"NDPrototype\"><div class=\"PSection PPlainSection\">GenericList genericList</div></div><div class=\"TTSummary\">The underlying storage and memory management for the string.</div></div>",41:"<div class=\"NDToolTip TVariable LC\"><div id=\"NDPrototype41\" class=\"NDPrototype\"><div class=\"PSection PPlainSection\"><span class=\"SHKeyword\">char</span> *str</div></div></div>",42:"<div class=\"NDToolTip TVariable LC\"><div id=\"NDPrototype42\" class=\"NDPrototype\"><div class=\"PSection PPlainSection\"><span class=\"SHKeyword\">int</span> length</div></div><div class=\"TTSummary\">The length of the string excluding the NULL terminator.</div></div>",43:"<div class=\"NDToolTip TClass LC\"><div class=\"NDClassPrototype\" id=\"NDClassPrototype43\"><div class=\"CPEntry TClass Current\"><div class=\"CPModifiers\"><span class=\"SHKeyword\">extern const</span> <span class=\"SHKeyword\">struct</span></div><div class=\"CPName\">String_t</div></div></div><div class=\"TTSummary\">The struct that creates and performs operations on objects of type String.</div></div>",65:"<div class=\"NDToolTip TFunction LC\"><div id=\"NDPrototype65\" class=\"NDPrototype WideForm\"><div class=\"PSection PParameterSection CStyle\"><table><tr><td class=\"PBeforeParameters\"><span class=\"SHKeyword\">bool</span> (</td><td class=\"PParametersParentCell\"><table class=\"PParameters\"><tr><td class=\"PSymbols first\">*</td><td class=\"PName last\">setSize</td></tr></table></td><td class=\"PAfterParameters\">)(String *self, <span class=\"SHKeyword\">const int</span> len)</td></tr></table></div></div><div class=\"TTSummary\">Allocates enough space for a string of length len+1. (for NULL terminator) Contents of the string will not be changed unless the new size is less than the current size.&nbsp; No terminating NULL character is added, this is purely just to set the size of the underlying array.&nbsp; If len==0 then String_t.clear will be called.</div></div>",79:"<div class=\"NDToolTip TFunction LC\"><div id=\"NDPrototype79\" class=\"NDPrototype WideForm\"><div class=\"PSection PParameterSection CStyle\"><table><tr><td class=\"PBeforeParameters\"><span class=\"SHKeyword\">bool</span> (</td><td class=\"PParametersParentCell\"><table class=\"PParameters\"><tr><td class=\"PSymbols first\">*</td><td class=\"PName last\">set</td></tr></table></td><td class=\"PAfterParameters\">)(String *self, <span class=\"SHKeyword\">const char</span> * <span class=\"SHKeyword\">const</span> newStr)</td></tr></table></div></div><div class=\"TTSummary\">Copies the contents of a NULL terminated string.</div></div>",83:"<div class=\"NDToolTip TFunction LC\"><div id=\"NDPrototype83\" class=\"NDPrototype WideForm\"><div class=\"PSection PParameterSection CStyle\"><table><tr><td class=\"PBeforeParameters\"><span class=\"SHKeyword\">bool</span> (</td><td class=\"PParametersParentCell\"><table class=\"PParameters\"><tr><td class=\"PSymbols first\">*</td><td class=\"PName last\">setNonNullString</td></tr></table></td><td class=\"PAfterParameters\">)(String *self, <span class=\"SHKeyword\">const char</span> * <span class=\"SHKeyword\">const</span> newStr, <span class=\"SHKeyword\">const int</span> strLen)</td></tr></table></div></div><div class=\"TTSummary\">Copies the contents of a non-NULL terminated string.</div></div>",84:"<div class=\"NDToolTip TFunction LC\"><div id=\"NDPrototype84\" class=\"NDPrototype WideForm\"><div class=\"PSection PParameterSection CStyle\"><table><tr><td class=\"PBeforeParameters\"><span class=\"SHKeyword\">bool</span> (</td><td class=\"PParametersParentCell\"><table class=\"PParameters\"><tr><td class=\"PSymbols first\">*</td><td class=\"PName last\">concat</td></tr></table></td><td class=\"PAfterParameters\">)(String *self, <span class=\"SHKeyword\">const char</span> * <span class=\"SHKeyword\">const</span> newStr)</td></tr></table></div></div><div class=\"TTSummary\">Appends a NULL terminated string to the current string.</div></div>",85:"<div class=\"NDToolTip TFunction LC\"><div id=\"NDPrototype85\" class=\"NDPrototype WideForm\"><div class=\"PSection PParameterSection CStyle\"><table><tr><td class=\"PBeforeParameters\"><span class=\"SHKeyword\">bool</span> (</td><td class=\"PParametersParentCell\"><table class=\"PParameters\"><tr><td class=\"PSymbols first\">*</td><td class=\"PName last\">concatChar</td></tr></table></td><td class=\"PAfterParameters\">)(String *self, <span class=\"SHKeyword\">const char</span> newChar)</td></tr></table></div></div><div class=\"TTSummary\">Appends a character to the current string.</div></div>",86:"<div class=\"NDToolTip TFunction LC\"><div id=\"NDPrototype86\" class=\"NDPrototype WideForm\"><div class=\"PSection PParameterSection CStyle\"><table><tr><td class=\"PBeforeParameters\"><span class=\"SHKeyword\">bool</span> (</td><td class=\"PParametersParentCell\"><table class=\"PParameters\"><tr><td class=\"PSymbols first\">*</td><td class=\"PName last\">copyOtherBetween</td></tr></table></td><td class=\"PAfterParameters\">)(String *self, <span class=\"SHKeyword\">const</span> String * <span class=\"SHKeyword\">const</span> other, <span class=\"SHKeyword\">const int</span> startIndex, <span class=\"SHKeyword\">const int</span> endIndex)</td></tr></table></div></div><div class=\"TTSummary\">Copies another string given the supplied indexes.</div></div>",51:"<div class=\"NDToolTip TFunction LC\"><div id=\"NDPrototype51\" class=\"NDPrototype WideForm\"><div class=\"PSection PParameterSection CStyle\"><table><tr><td class=\"PBeforeParameters\"><span class=\"SHKeyword\">void</span> (</td><td class=\"PParametersParentCell\"><table class=\"PParameters\"><tr><td class=\"PSymbols first\">*</td><td class=\"PName last\">toUpper</td></tr></table></td><td class=\"PAfterParameters\">)(String *self)</td></tr></table></div></div><div class=\"TTSummary\">Makes a string uppercase.</div></div>",52:"<div class=\"NDToolTip TFunction LC\"><div id=\"NDPrototype52\" class=\"NDPrototype WideForm\"><div class=\"PSection PParameterSection CStyle\"><table><tr><td class=\"PBeforeParameters\"><span class=\"SHKeyword\">void</span> (</td><td class=\"PParametersParentCell\"><table class=\"PParameters\"><tr><td class=\"PSymbols first\">*</td><td class=\"PName last\">toLower</td></tr></table></td><td class=\"PAfterParameters\">)(String *self)</td></tr></table></div></div><div class=\"TTSummary\">Makes a string lowercase.</div></div>",53:"<div class=\"NDToolTip TFunction LC\"><div id=\"NDPrototype53\" class=\"NDPrototype WideForm\"><div class=\"PSection PParameterSection CStyle\"><table><tr><td class=\"PBeforeParameters\"><span class=\"SHKeyword\">int</span> (</td><td class=\"PParametersParentCell\"><table class=\"PParameters\"><tr><td class=\"PSymbols first\">*</td><td class=\"PName last\">contains</td></tr></table></td><td class=\"PAfterParameters\">)(<span class=\"SHKeyword\">const</span> String *self, <span class=\"SHKeyword\">const char</span> * <span class=\"SHKeyword\">const</span> token)</td></tr></table></div></div><div class=\"TTSummary\">Returns the index of where the substring starts in the current string, or -1 if not present.</div></div>",54:"<div class=\"NDToolTip TFunction LC\"><div id=\"NDPrototype54\" class=\"NDPrototype WideForm\"><div class=\"PSection PParameterSection CStyle\"><table><tr><td class=\"PBeforeParameters\"><span class=\"SHKeyword\">int</span> (</td><td class=\"PParametersParentCell\"><table class=\"PParameters\"><tr><td class=\"PSymbols first\">*</td><td class=\"PName last\">getFirstIndexOf</td></tr></table></td><td class=\"PAfterParameters\">)(<span class=\"SHKeyword\">const</span> String * <span class=\"SHKeyword\">const</span> self, <span class=\"SHKeyword\">const char</span> searchChar)</td></tr></table></div></div><div class=\"TTSummary\">Finds the first instance of the given char in the string.</div></div>",55:"<div class=\"NDToolTip TFunction LC\"><div id=\"NDPrototype55\" class=\"NDPrototype WideForm\"><div class=\"PSection PParameterSection CStyle\"><table><tr><td class=\"PBeforeParameters\"><span class=\"SHKeyword\">int</span> (</td><td class=\"PParametersParentCell\"><table class=\"PParameters\"><tr><td class=\"PSymbols first\">*</td><td class=\"PName last\">getLastIndexOf</td></tr></table></td><td class=\"PAfterParameters\">)(<span class=\"SHKeyword\">const</span> String * <span class=\"SHKeyword\">const</span> self, <span class=\"SHKeyword\">const char</span> searchChar)</td></tr></table></div></div><div class=\"TTSummary\">Finds the last instance of the given char in the string.</div></div>",56:"<div class=\"NDToolTip TFunction LC\"><div id=\"NDPrototype56\" class=\"NDPrototype WideForm\"><div class=\"PSection PParameterSection CStyle\"><table><tr><td class=\"PBeforeParameters\"><span class=\"SHKeyword\">int</span> (</td><td class=\"PParametersParentCell\"><table class=\"PParameters\"><tr><td class=\"PSymbols first\">*</td><td class=\"PName last\">getCharOccurrences</td></tr></table></td><td class=\"PAfterParameters\">)(<span class=\"SHKeyword\">const</span> String *self, <span class=\"SHKeyword\">const char</span> *searchChars)</td></tr></table></div></div><div class=\"TTSummary\">Counts the number of occurrences of the characters in searchChars in the current string.</div></div>",87:"<div class=\"NDToolTip TFunction LC\"><div id=\"NDPrototype87\" class=\"NDPrototype WideForm\"><div class=\"PSection PParameterSection CStyle\"><table><tr><td class=\"PBeforeParameters\"><span class=\"SHKeyword\">bool</span> (</td><td class=\"PParametersParentCell\"><table class=\"PParameters\"><tr><td class=\"PSymbols first\">*</td><td class=\"PName last\">trimWhitespace</td></tr></table></td><td class=\"PAfterParameters\">)(String *self)</td></tr></table></div></div><div class=\"TTSummary\">Removes whitespace characters (\' \',\'\\t\') from the beginning and end of the string.</div></div>",88:"<div class=\"NDToolTip TFunction LC\"><div id=\"NDPrototype88\" class=\"NDPrototype WideForm\"><div class=\"PSection PParameterSection CStyle\"><table><tr><td class=\"PBeforeParameters\"><span class=\"SHKeyword\">bool</span> (</td><td class=\"PParametersParentCell\"><table class=\"PParameters\"><tr><td class=\"PSymbols first\">*</td><td class=\"PName last\">removeChars</td></tr></table></td><td class=\"PAfterParameters\">)(String *self, <span class=\"SHKeyword\">const char</span> * <span class=\"SHKeyword\">const</span> unwantedChars)</td></tr></table></div></div><div class=\"TTSummary\">Removes the supplied chars from the string.&nbsp; If all of the characters are removed from the string then the string is cleared.</div></div>",89:"<div class=\"NDToolTip TFunction LC\"><div id=\"NDPrototype89\" class=\"NDPrototype WideForm\"><div class=\"PSection PParameterSection CStyle\"><table><tr><td class=\"PBeforeParameters\"><span class=\"SHKeyword\">bool</span> (</td><td class=\"PParametersParentCell\"><table class=\"PParameters\"><tr><td class=\"PSymbols first\">*</td><td class=\"PName last\">clear</td></tr></table></td><td class=\"PAfterParameters\">)(String *self)</td></tr></table></div></div><div class=\"TTSummary\">Clears the contents of the string, sets length to 0.</div></div>",60:"<div class=\"NDToolTip TFunction LC\"><div id=\"NDPrototype60\" class=\"NDPrototype WideForm\"><div class=\"PSection PParameterSection CStyle\"><table><tr><td class=\"PBeforeParameters\"><span class=\"SHKeyword\">bool</span> (</td><td class=\"PParametersParentCell\"><table class=\"PParameters\"><tr><td class=\"PSymbols first\">*</td><td class=\"PName last\">equalsCharArray</td></tr></table></td><td class=\"PAfterParameters\">)(<span class=\"SHKeyword\">const</span> String * <span class=\"SHKeyword\">const</span> self, <span class=\"SHKeyword\">const char</span> * <span class=\"SHKeyword\">const</span> other)</td></tr></table></div></div><div class=\"TTSummary\">Returns true/false depending if the strings are equal or not.&nbsp; Two NULL strings are considered equal. Two empty strings are considered equal.</div></div>"});