﻿NDSummary.OnToolTipsLoaded("File:collections/GenericList.h",{22:"<div class=\"NDToolTip TClass LC\"><div class=\"NDClassPrototype\" id=\"NDClassPrototype22\"><div class=\"CPEntry TClass Current\"><div class=\"CPModifiers\"><span class=\"SHKeyword\">typedef</span> <span class=\"SHKeyword\">struct</span></div><div class=\"CPName\">GenericList</div></div></div><div class=\"TTSummary\">The struct that represents a GenericList.</div></div>",12:"<div class=\"NDToolTip TVariable LC\"><div id=\"NDPrototype12\" class=\"NDPrototype\"><div class=\"PSection PPlainSection\"><span class=\"SHKeyword\">void</span> *list</div></div></div>",13:"<div class=\"NDToolTip TVariable LC\"><div id=\"NDPrototype13\" class=\"NDPrototype\"><div class=\"PSection PPlainSection\"><span class=\"SHKeyword\">int</span> listSize</div></div><div class=\"TTSummary\">Holds the actual size of the internal list.</div></div>",14:"<div class=\"NDToolTip TVariable LC\"><div id=\"NDPrototype14\" class=\"NDPrototype\"><div class=\"PSection PPlainSection\"><span class=\"SHKeyword\">bool</span> strictAlloc</div></div><div class=\"TTSummary\">Determines how memory is allocated.</div></div>",15:"<div class=\"NDToolTip TVariable LC\"><div id=\"NDPrototype15\" class=\"NDPrototype\"><div class=\"PSection PPlainSection\"><span class=\"SHKeyword\">int</span> numElements</div></div><div class=\"TTSummary\">Holds how many elements are in the list, may or may not the same as the internal lists actual size.</div></div>",16:"<div class=\"NDToolTip TVariable LC\"><div id=\"NDPrototype16\" class=\"NDPrototype\"><div class=\"PSection PPlainSection\">size_t elementSize</div></div><div class=\"TTSummary\">Holds the element size so that pointer arithmetic can be performed with the void pointer.</div></div>",20:"<div class=\"NDToolTip TVariable LC\"><div id=\"NDPrototype20\" class=\"NDPrototype\"><div class=\"PSection PPlainSection\"><span class=\"SHKeyword\">const</span> Class *elementClass</div></div><div class=\"TTSummary\">A pointer to the element class so that elements will be created and destroyed properly.</div></div>",17:"<div class=\"NDToolTip TClass LC\"><div class=\"NDClassPrototype\" id=\"NDClassPrototype17\"><div class=\"CPEntry TClass Current\"><div class=\"CPModifiers\"><span class=\"SHKeyword\">extern const</span> <span class=\"SHKeyword\">struct</span></div><div class=\"CPName\">GenericList_t</div></div></div><div class=\"TTSummary\">The struct that creates and performs operations on objects of type GenericList.</div></div>",45:"<div class=\"NDToolTip TFunction LC\"><div id=\"NDPrototype45\" class=\"NDPrototype WideForm\"><div class=\"PSection PParameterSection CStyle\"><table><tr><td class=\"PBeforeParameters\"><span class=\"SHKeyword\">bool</span> (</td><td class=\"PParametersParentCell\"><table class=\"PParameters\"><tr><td class=\"PSymbols first\">*</td><td class=\"PName last\">setElementType</td></tr></table></td><td class=\"PAfterParameters\">)(GenericList *self, <span class=\"SHKeyword\">const</span> Class * <span class=\"SHKeyword\">const</span> newClass, <span class=\"SHKeyword\">const</span> size_t newSize)</td></tr></table></div></div><div class=\"TTSummary\">Sets the size and type of the elements stored in the list.</div></div>",46:"<div class=\"NDToolTip TFunction LC\"><div id=\"NDPrototype46\" class=\"NDPrototype WideForm\"><div class=\"PSection PParameterSection CStyle\"><table><tr><td class=\"PBeforeParameters\"><span class=\"SHKeyword\">bool</span> (</td><td class=\"PParametersParentCell\"><table class=\"PParameters\"><tr><td class=\"PSymbols first\">*</td><td class=\"PName last\">setListSize</td></tr></table></td><td class=\"PAfterParameters\">)(GenericList *self, <span class=\"SHKeyword\">const int</span> numElements)</td></tr></table></div></div><div class=\"TTSummary\">Useful for reducing the number of memory reallocations if you know the final size of the list.&nbsp; Contents of the list will not be changed unless the new size is less than the current size.&nbsp; numElements will not be updated, and future calls should assume that the list is \'empty\' or contains what was previously held in the array.&nbsp; The elements constructors will not be called to initialize each object, this is purely just to set the size of the underlying array.</div></div>",21:"<div class=\"NDToolTip TFunction LC\"><div id=\"NDPrototype21\" class=\"NDPrototype WideForm\"><div class=\"PSection PParameterSection CStyle\"><table><tr><td class=\"PBeforeParameters\"><span class=\"SHKeyword\">bool</span> (</td><td class=\"PParametersParentCell\"><table class=\"PParameters\"><tr><td class=\"PSymbols first\">*</td><td class=\"PName last\">setNumElements</td></tr></table></td><td class=\"PAfterParameters\">)(GenericList *self, <span class=\"SHKeyword\">const int</span> numElements)</td></tr></table></div></div><div class=\"TTSummary\">Sets the size of the list and calls the elements constructors defined by GenericList.elementClass to initialize each object that is created (if any).&nbsp; If the given number of elements is less than the current number of elements, GenericList_t.removeBetween will be called to remove the appropriate number of elements from the end of the list.</div></div>",48:"<div class=\"NDToolTip TFunction LC\"><div id=\"NDPrototype48\" class=\"NDPrototype WideForm\"><div class=\"PSection PParameterSection CStyle\"><table><tr><td class=\"PBeforeParameters\"><span class=\"SHKeyword\">bool</span> (</td><td class=\"PParametersParentCell\"><table class=\"PParameters\"><tr><td class=\"PSymbols first\">*</td><td class=\"PName last\">set</td></tr></table></td><td class=\"PAfterParameters\">)(GenericList *self, <span class=\"SHKeyword\">const void</span> * <span class=\"SHKeyword\">const</span> newElements, <span class=\"SHKeyword\">const int</span> numElements)</td></tr></table></div></div><div class=\"TTSummary\">Sets the list with the given data, clearing any data that was previously held in the list.</div></div>",49:"<div class=\"NDToolTip TFunction LC\"><div id=\"NDPrototype49\" class=\"NDPrototype WideForm\"><div class=\"PSection PParameterSection CStyle\"><table><tr><td class=\"PBeforeParameters\"><span class=\"SHKeyword\">bool</span> (</td><td class=\"PParametersParentCell\"><table class=\"PParameters\"><tr><td class=\"PSymbols first\">*</td><td class=\"PName last\">setAt</td></tr></table></td><td class=\"PAfterParameters\">)(GenericList *self, <span class=\"SHKeyword\">const void</span> * <span class=\"SHKeyword\">const</span> newElements, <span class=\"SHKeyword\">const int</span> numElements, <span class=\"SHKeyword\">const int</span> index)</td></tr></table></div></div><div class=\"TTSummary\">Sets the selected elements in the list, up to the end of the list.</div></div>",50:"<div class=\"NDToolTip TFunction LC\"><div id=\"NDPrototype50\" class=\"NDPrototype WideForm\"><div class=\"PSection PParameterSection CStyle\"><table><tr><td class=\"PBeforeParameters\"><span class=\"SHKeyword\">bool</span> (</td><td class=\"PParametersParentCell\"><table class=\"PParameters\"><tr><td class=\"PSymbols first\">*</td><td class=\"PName last\">add</td></tr></table></td><td class=\"PAfterParameters\">)(GenericList *self, <span class=\"SHKeyword\">const void</span> * <span class=\"SHKeyword\">const</span> newElements, <span class=\"SHKeyword\">const int</span> numElements)</td></tr></table></div></div><div class=\"TTSummary\">Appends the given elements to the list</div></div>",57:"<div class=\"NDToolTip TFunction LC\"><div id=\"NDPrototype57\" class=\"NDPrototype WideForm\"><div class=\"PSection PParameterSection CStyle\"><table><tr><td class=\"PBeforeParameters\"><span class=\"SHKeyword\">bool</span> (</td><td class=\"PParametersParentCell\"><table class=\"PParameters\"><tr><td class=\"PSymbols first\">*</td><td class=\"PName last\">addAt</td></tr></table></td><td class=\"PAfterParameters\">)(GenericList *self, <span class=\"SHKeyword\">const void</span> * <span class=\"SHKeyword\">const</span> newElement, <span class=\"SHKeyword\">const int</span> numElements, <span class=\"SHKeyword\">const int</span> index)</td></tr></table></div></div><div class=\"TTSummary\">Inserts the given elements into the list</div></div>",58:"<div class=\"NDToolTip TFunction LC\"><div id=\"NDPrototype58\" class=\"NDPrototype WideForm\"><div class=\"PSection PParameterSection CStyle\"><table><tr><td class=\"PBeforeParameters\"><span class=\"SHKeyword\">bool</span> (</td><td class=\"PParametersParentCell\"><table class=\"PParameters\"><tr><td class=\"PSymbols first\">*</td><td class=\"PName last\">copyOtherBetween</td></tr></table></td><td class=\"PAfterParameters\">)(GenericList *self, <span class=\"SHKeyword\">const</span> GenericList * <span class=\"SHKeyword\">const</span> other, <span class=\"SHKeyword\">const int</span> startIndex, <span class=\"SHKeyword\">const int</span> endIndex)</td></tr></table></div></div><div class=\"TTSummary\">Copies the selected data from another GenericList. If elements are already in the list then GenericList_t.clear is called.</div></div>",26:"<div class=\"NDToolTip TFunction LC\"><div id=\"NDPrototype26\" class=\"NDPrototype WideForm\"><div class=\"PSection PParameterSection CStyle\"><table><tr><td class=\"PBeforeParameters\"><span class=\"SHKeyword\">void</span>* (</td><td class=\"PParametersParentCell\"><table class=\"PParameters\"><tr><td class=\"PSymbols first\">*</td><td class=\"PName last\">get</td></tr></table></td><td class=\"PAfterParameters\">)(<span class=\"SHKeyword\">const</span> GenericList * <span class=\"SHKeyword\">const</span> self, <span class=\"SHKeyword\">const int</span> index)</td></tr></table></div></div><div class=\"TTSummary\">Gets the selected element from the list.</div></div>",59:"<div class=\"NDToolTip TFunction LC\"><div id=\"NDPrototype59\" class=\"NDPrototype WideForm\"><div class=\"PSection PParameterSection CStyle\"><table><tr><td class=\"PBeforeParameters\"><span class=\"SHKeyword\">bool</span> (</td><td class=\"PParametersParentCell\"><table class=\"PParameters\"><tr><td class=\"PSymbols first\">*</td><td class=\"PName last\">contains</td></tr></table></td><td class=\"PAfterParameters\">)(<span class=\"SHKeyword\">const</span> GenericList * <span class=\"SHKeyword\">const</span> self, <span class=\"SHKeyword\">const void</span> * <span class=\"SHKeyword\">const</span> token)</td></tr></table></div></div><div class=\"TTSummary\">Returns true/false depending on if the given token is in the list. Searching will stop once the first instance is found.</div></div>",28:"<div class=\"NDToolTip TFunction LC\"><div id=\"NDPrototype28\" class=\"NDPrototype WideForm\"><div class=\"PSection PParameterSection CStyle\"><table><tr><td class=\"PBeforeParameters\"><span class=\"SHKeyword\">int</span> (</td><td class=\"PParametersParentCell\"><table class=\"PParameters\"><tr><td class=\"PSymbols first\">*</td><td class=\"PName last\">getFirstIndexOf</td></tr></table></td><td class=\"PAfterParameters\">)(<span class=\"SHKeyword\">const</span> GenericList * <span class=\"SHKeyword\">const</span> self, <span class=\"SHKeyword\">const void</span> * <span class=\"SHKeyword\">const</span> token)</td></tr></table></div></div><div class=\"TTSummary\">Returns the first index of where token is in the list. If not present in the list, it returns -1.</div></div>",29:"<div class=\"NDToolTip TFunction LC\"><div id=\"NDPrototype29\" class=\"NDPrototype WideForm\"><div class=\"PSection PParameterSection CStyle\"><table><tr><td class=\"PBeforeParameters\"><span class=\"SHKeyword\">int</span> (</td><td class=\"PParametersParentCell\"><table class=\"PParameters\"><tr><td class=\"PSymbols first\">*</td><td class=\"PName last\">getLastIndexOf</td></tr></table></td><td class=\"PAfterParameters\">)(<span class=\"SHKeyword\">const</span> GenericList * <span class=\"SHKeyword\">const</span> self, <span class=\"SHKeyword\">const void</span> * <span class=\"SHKeyword\">const</span> token)</td></tr></table></div></div><div class=\"TTSummary\">Returns the last index of where token is in the list. If not present in the list, it returns -1.</div></div>",90:"<div class=\"NDToolTip TFunction LC\"><div id=\"NDPrototype90\" class=\"NDPrototype WideForm\"><div class=\"PSection PParameterSection CStyle\"><table><tr><td class=\"PBeforeParameters\"><span class=\"SHKeyword\">bool</span> (</td><td class=\"PParametersParentCell\"><table class=\"PParameters\"><tr><td class=\"PSymbols first\">*</td><td class=\"PName last\">remove</td></tr></table></td><td class=\"PAfterParameters\">)(GenericList *self, <span class=\"SHKeyword\">const void</span> * <span class=\"SHKeyword\">const</span> token)</td></tr></table></div></div><div class=\"TTSummary\">Removes all instances of the supplied token from the list. The destructor in the GenericList.elementClass struct will be called for each element that is deleted.</div></div>",91:"<div class=\"NDToolTip TFunction LC\"><div id=\"NDPrototype91\" class=\"NDPrototype WideForm\"><div class=\"PSection PParameterSection CStyle\"><table><tr><td class=\"PBeforeParameters\"><span class=\"SHKeyword\">bool</span> (</td><td class=\"PParametersParentCell\"><table class=\"PParameters\"><tr><td class=\"PSymbols first\">*</td><td class=\"PName last\">removeAll</td></tr></table></td><td class=\"PAfterParameters\">)(GenericList *self, <span class=\"SHKeyword\">const void</span> *<span class=\"SHKeyword\">const</span> tokens, <span class=\"SHKeyword\">const int</span> numTokens)</td></tr></table></div></div><div class=\"TTSummary\">Removes all instances of the supplied tokens from the list. The destructor in the GenericList.elementClass struct will be called for each element that is deleted.</div></div>",92:"<div class=\"NDToolTip TFunction LC\"><div id=\"NDPrototype92\" class=\"NDPrototype WideForm\"><div class=\"PSection PParameterSection CStyle\"><table><tr><td class=\"PBeforeParameters\"><span class=\"SHKeyword\">bool</span> (</td><td class=\"PParametersParentCell\"><table class=\"PParameters\"><tr><td class=\"PSymbols first\">*</td><td class=\"PName last\">removeAt</td></tr></table></td><td class=\"PAfterParameters\">)(GenericList *self, <span class=\"SHKeyword\">const int</span> index)</td></tr></table></div></div><div class=\"TTSummary\">Removes the item at the supplied index from the list. The destructor in the GenericList.elementClass struct will be called for each element that is deleted.</div></div>",93:"<div class=\"NDToolTip TFunction LC\"><div id=\"NDPrototype93\" class=\"NDPrototype WideForm\"><div class=\"PSection PParameterSection CStyle\"><table><tr><td class=\"PBeforeParameters\"><span class=\"SHKeyword\">bool</span> (</td><td class=\"PParametersParentCell\"><table class=\"PParameters\"><tr><td class=\"PSymbols first\">*</td><td class=\"PName last\">removeBetween</td></tr></table></td><td class=\"PAfterParameters\">)(GenericList *self, <span class=\"SHKeyword\">const int</span> startIndex, <span class=\"SHKeyword\">const int</span> endIndex)</td></tr></table></div></div><div class=\"TTSummary\">Removes the items between the supplied indexes. The destructor in the GenericList.elementClass struct will be called for each element that is deleted.</div></div>",94:"<div class=\"NDToolTip TFunction LC\"><div id=\"NDPrototype94\" class=\"NDPrototype WideForm\"><div class=\"PSection PParameterSection CStyle\"><table><tr><td class=\"PBeforeParameters\"><span class=\"SHKeyword\">bool</span> (</td><td class=\"PParametersParentCell\"><table class=\"PParameters\"><tr><td class=\"PSymbols first\">*</td><td class=\"PName last\">trimToSize</td></tr></table></td><td class=\"PAfterParameters\">)(GenericList *self)</td></tr></table></div></div><div class=\"TTSummary\">Reallocates the internal memory so that numElements==listSize.</div></div>",95:"<div class=\"NDToolTip TFunction LC\"><div id=\"NDPrototype95\" class=\"NDPrototype WideForm\"><div class=\"PSection PParameterSection CStyle\"><table><tr><td class=\"PBeforeParameters\"><span class=\"SHKeyword\">bool</span> (</td><td class=\"PParametersParentCell\"><table class=\"PParameters\"><tr><td class=\"PSymbols first\">*</td><td class=\"PName last\">clear</td></tr></table></td><td class=\"PAfterParameters\">)(GenericList *self)</td></tr></table></div></div><div class=\"TTSummary\">Removes all elements from the list and frees the underlying memory. The destructor in the GenericList.elementClass struct will be called for each element that is deleted.</div></div>",96:"<div class=\"NDToolTip TFunction LC\"><div id=\"NDPrototype96\" class=\"NDPrototype WideForm\"><div class=\"PSection PParameterSection CStyle\"><table><tr><td class=\"PBeforeParameters\"><span class=\"SHKeyword\">bool</span> (</td><td class=\"PParametersParentCell\"><table class=\"PParameters\"><tr><td class=\"PSymbols first\">*</td><td class=\"PName last\">clearElements</td></tr></table></td><td class=\"PAfterParameters\">)(GenericList *self)</td></tr></table></div></div><div class=\"TTSummary\">Removes all elements from the list but does not free the underlying memory.&nbsp; The destructor in the GenericList.elementClass struct will be called for each element that is deleted.&nbsp; This does not create a memory leak because the actual list size is tracked by GenericList.listSize.</div></div>",37:"<div class=\"NDToolTip TFunction LC\"><div id=\"NDPrototype37\" class=\"NDPrototype WideForm\"><div class=\"PSection PParameterSection CStyle\"><table><tr><td class=\"PBeforeParameters\"><span class=\"SHKeyword\">bool</span> (</td><td class=\"PParametersParentCell\"><table class=\"PParameters\"><tr><td class=\"PSymbols first\">*</td><td class=\"PName last\">isEmpty</td></tr></table></td><td class=\"PAfterParameters\">)(<span class=\"SHKeyword\">const</span> GenericList * <span class=\"SHKeyword\">const</span> self)</td></tr></table></div></div><div class=\"TTSummary\">Returns true or false depending on weather the list is empty or not.</div></div>"});