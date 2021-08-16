﻿NDSummary.OnToolTipsLoaded("CClass:String_t",{2:"<div class=\"NDToolTip TClass LC\"><div class=\"NDClassPrototype\" id=\"NDClassPrototype2\"><div class=\"CPEntry TClass Current\"><div class=\"CPModifiers\"><span class=\"SHKeyword\">extern const</span> <span class=\"SHKeyword\">struct</span></div><div class=\"CPName\">String_t</div></div></div><div class=\"TTSummary\">The struct that creates and performs operations on objects of type String.</div></div>",52:"<div class=\"NDToolTip TFunction LC\"><div id=\"NDPrototype52\" class=\"NDPrototype WideForm\"><div class=\"PSection PParameterSection CStyle\"><table><tr><td class=\"PBeforeParameters\"><span class=\"SHKeyword\">bool</span> (</td><td class=\"PParametersParentCell\"><table class=\"PParameters\"><tr><td class=\"PSymbols first\">*</td><td class=\"PName last\">set</td></tr></table></td><td class=\"PAfterParameters\">)(String *self, <span class=\"SHKeyword\">const char</span> * <span class=\"SHKeyword\">const</span> newStr)</td></tr></table></div></div><div class=\"TTSummary\">Copies the contents of a NULL terminated string.</div></div>",37:"<div class=\"NDToolTip TFunction LC\"><div id=\"NDPrototype37\" class=\"NDPrototype WideForm\"><div class=\"PSection PParameterSection CStyle\"><table><tr><td class=\"PBeforeParameters\"><span class=\"SHKeyword\">bool</span> (</td><td class=\"PParametersParentCell\"><table class=\"PParameters\"><tr><td class=\"PSymbols first\">*</td><td class=\"PName last\">setNonNullString</td></tr></table></td><td class=\"PAfterParameters\">)(String *self, <span class=\"SHKeyword\">const char</span> * <span class=\"SHKeyword\">const</span> newStr, <span class=\"SHKeyword\">const int</span> strLen)</td></tr></table></div></div><div class=\"TTSummary\">Copies the contents of a non-NULL terminated string.</div></div>",40:"<div class=\"NDToolTip TFunction LC\"><div id=\"NDPrototype40\" class=\"NDPrototype WideForm\"><div class=\"PSection PParameterSection CStyle\"><table><tr><td class=\"PBeforeParameters\"><span class=\"SHKeyword\">bool</span> (</td><td class=\"PParametersParentCell\"><table class=\"PParameters\"><tr><td class=\"PSymbols first\">*</td><td class=\"PName last\">concat</td></tr></table></td><td class=\"PAfterParameters\">)(String *self, <span class=\"SHKeyword\">const char</span> * <span class=\"SHKeyword\">const</span> newStr)</td></tr></table></div></div><div class=\"TTSummary\">Appends a NULL terminated string to the current string.</div></div>",41:"<div class=\"NDToolTip TFunction LC\"><div id=\"NDPrototype41\" class=\"NDPrototype WideForm\"><div class=\"PSection PParameterSection CStyle\"><table><tr><td class=\"PBeforeParameters\"><span class=\"SHKeyword\">bool</span> (</td><td class=\"PParametersParentCell\"><table class=\"PParameters\"><tr><td class=\"PSymbols first\">*</td><td class=\"PName last\">concatChar</td></tr></table></td><td class=\"PAfterParameters\">)(String *self, <span class=\"SHKeyword\">const char</span> newChar)</td></tr></table></div></div><div class=\"TTSummary\">Appends a character to the current string.</div></div>",54:"<div class=\"NDToolTip TFunction LC\"><div id=\"NDPrototype54\" class=\"NDPrototype WideForm\"><div class=\"PSection PParameterSection CStyle\"><table><tr><td class=\"PBeforeParameters\"><span class=\"SHKeyword\">bool</span> (</td><td class=\"PParametersParentCell\"><table class=\"PParameters\"><tr><td class=\"PSymbols first\">*</td><td class=\"PName last\">copyOtherBetween</td></tr></table></td><td class=\"PAfterParameters\">)(String *self, <span class=\"SHKeyword\">const</span> String * <span class=\"SHKeyword\">const</span> other, <span class=\"SHKeyword\">const int</span> startIndex, <span class=\"SHKeyword\">const int</span> endIndex)</td></tr></table></div></div><div class=\"TTSummary\">Copies another string given the supplied indexes.</div></div>",8:"<div class=\"NDToolTip TFunction LC\"><div id=\"NDPrototype8\" class=\"NDPrototype WideForm\"><div class=\"PSection PParameterSection CStyle\"><table><tr><td class=\"PBeforeParameters\"><span class=\"SHKeyword\">void</span> (</td><td class=\"PParametersParentCell\"><table class=\"PParameters\"><tr><td class=\"PSymbols first\">*</td><td class=\"PName last\">toUpper</td></tr></table></td><td class=\"PAfterParameters\">)(String *self)</td></tr></table></div></div><div class=\"TTSummary\">Makes a string uppercase.</div></div>",32:"<div class=\"NDToolTip TFunction LC\"><div id=\"NDPrototype32\" class=\"NDPrototype WideForm\"><div class=\"PSection PParameterSection CStyle\"><table><tr><td class=\"PBeforeParameters\"><span class=\"SHKeyword\">void</span> (</td><td class=\"PParametersParentCell\"><table class=\"PParameters\"><tr><td class=\"PSymbols first\">*</td><td class=\"PName last\">toLower</td></tr></table></td><td class=\"PAfterParameters\">)(String *self)</td></tr></table></div></div><div class=\"TTSummary\">Makes a string lowercase.</div></div>",60:"<div class=\"NDToolTip TFunction LC\"><div id=\"NDPrototype60\" class=\"NDPrototype WideForm\"><div class=\"PSection PParameterSection CStyle\"><table><tr><td class=\"PBeforeParameters\"><span class=\"SHKeyword\">int</span> (</td><td class=\"PParametersParentCell\"><table class=\"PParameters\"><tr><td class=\"PSymbols first\">*</td><td class=\"PName last\">contains</td></tr></table></td><td class=\"PAfterParameters\">)(<span class=\"SHKeyword\">const</span> String *self, <span class=\"SHKeyword\">const char</span> * <span class=\"SHKeyword\">const</span> token)</td></tr></table></div></div><div class=\"TTSummary\">Returns the index of where the substring starts in the current string, or -1 if not present.</div></div>",47:"<div class=\"NDToolTip TFunction LC\"><div id=\"NDPrototype47\" class=\"NDPrototype WideForm\"><div class=\"PSection PParameterSection CStyle\"><table><tr><td class=\"PBeforeParameters\"><span class=\"SHKeyword\">int</span> (</td><td class=\"PParametersParentCell\"><table class=\"PParameters\"><tr><td class=\"PSymbols first\">*</td><td class=\"PName last\">getFirstIndexOf</td></tr></table></td><td class=\"PAfterParameters\">)(<span class=\"SHKeyword\">const</span> String * <span class=\"SHKeyword\">const</span> self, <span class=\"SHKeyword\">const char</span> searchChar)</td></tr></table></div></div><div class=\"TTSummary\">Finds the first instance of the given char in the string.</div></div>",50:"<div class=\"NDToolTip TFunction LC\"><div id=\"NDPrototype50\" class=\"NDPrototype WideForm\"><div class=\"PSection PParameterSection CStyle\"><table><tr><td class=\"PBeforeParameters\"><span class=\"SHKeyword\">int</span> (</td><td class=\"PParametersParentCell\"><table class=\"PParameters\"><tr><td class=\"PSymbols first\">*</td><td class=\"PName last\">getLastIndexOf</td></tr></table></td><td class=\"PAfterParameters\">)(<span class=\"SHKeyword\">const</span> String * <span class=\"SHKeyword\">const</span> self, <span class=\"SHKeyword\">const char</span> searchChar)</td></tr></table></div></div><div class=\"TTSummary\">Finds the last instance of the given char in the string.</div></div>",51:"<div class=\"NDToolTip TFunction LC\"><div id=\"NDPrototype51\" class=\"NDPrototype WideForm\"><div class=\"PSection PParameterSection CStyle\"><table><tr><td class=\"PBeforeParameters\"><span class=\"SHKeyword\">int</span> (</td><td class=\"PParametersParentCell\"><table class=\"PParameters\"><tr><td class=\"PSymbols first\">*</td><td class=\"PName last\">getCharOccurrences</td></tr></table></td><td class=\"PAfterParameters\">)(<span class=\"SHKeyword\">const</span> String *self, <span class=\"SHKeyword\">const char</span> *searchChars)</td></tr></table></div></div><div class=\"TTSummary\">Counts the number of occurrences of the characters in searchChars in the current string.</div></div>",67:"<div class=\"NDToolTip TFunction LC\"><div id=\"NDPrototype67\" class=\"NDPrototype WideForm\"><div class=\"PSection PParameterSection CStyle\"><table><tr><td class=\"PBeforeParameters\"><span class=\"SHKeyword\">bool</span> (</td><td class=\"PParametersParentCell\"><table class=\"PParameters\"><tr><td class=\"PSymbols first\">*</td><td class=\"PName last\">trimWhitespace</td></tr></table></td><td class=\"PAfterParameters\">)(String *self)</td></tr></table></div></div><div class=\"TTSummary\">Removes whitespace characters (\' \',\'\\t\') from the beginning and end of the string.</div></div>",61:"<div class=\"NDToolTip TFunction LC\"><div id=\"NDPrototype61\" class=\"NDPrototype WideForm\"><div class=\"PSection PParameterSection CStyle\"><table><tr><td class=\"PBeforeParameters\"><span class=\"SHKeyword\">bool</span> (</td><td class=\"PParametersParentCell\"><table class=\"PParameters\"><tr><td class=\"PSymbols first\">*</td><td class=\"PName last\">removeChars</td></tr></table></td><td class=\"PAfterParameters\">)(String *self, <span class=\"SHKeyword\">const char</span> * <span class=\"SHKeyword\">const</span> unwantedChars)</td></tr></table></div></div><div class=\"TTSummary\">Removes the supplied chars from the string.&nbsp; If all of the characters are removed from the string then the string is cleared.</div></div>",43:"<div class=\"NDToolTip TFunction LC\"><div id=\"NDPrototype43\" class=\"NDPrototype WideForm\"><div class=\"PSection PParameterSection CStyle\"><table><tr><td class=\"PBeforeParameters\"><span class=\"SHKeyword\">bool</span> (</td><td class=\"PParametersParentCell\"><table class=\"PParameters\"><tr><td class=\"PSymbols first\">*</td><td class=\"PName last\">clear</td></tr></table></td><td class=\"PAfterParameters\">)(String *self)</td></tr></table></div></div><div class=\"TTSummary\">Clears the contents of the string, sets length to 0.</div></div>",3:"<div class=\"NDToolTip TFunction LC\"><div id=\"NDPrototype3\" class=\"NDPrototype WideForm\"><div class=\"PSection PParameterSection CStyle\"><table><tr><td class=\"PBeforeParameters\"><span class=\"SHKeyword\">bool</span> (</td><td class=\"PParametersParentCell\"><table class=\"PParameters\"><tr><td class=\"PSymbols first\">*</td><td class=\"PName last\">equalsCharArray</td></tr></table></td><td class=\"PAfterParameters\">)(<span class=\"SHKeyword\">const</span> String * <span class=\"SHKeyword\">const</span> self, <span class=\"SHKeyword\">const char</span> * <span class=\"SHKeyword\">const</span> other)</td></tr></table></div></div><div class=\"TTSummary\">Returns true/false depending if the strings are equal or not.&nbsp; Two NULL strings are considered equal. Two empty strings are considered equal.</div></div>"});