﻿NDContentPage.OnToolTipsLoaded({13:"<div class=\"NDToolTip TVariable LC\"><div id=\"NDPrototype13\" class=\"NDPrototype\"><div class=\"PSection PPlainSection\"><span class=\"SHKeyword\">int</span> listSize</div></div><div class=\"TTSummary\">Holds the actual size of the internal list.</div></div>",17:"<div class=\"NDToolTip TClass LC\"><div class=\"NDClassPrototype\" id=\"NDClassPrototype17\"><div class=\"CPEntry TClass Current\"><div class=\"CPModifiers\"><span class=\"SHKeyword\">extern const</span> <span class=\"SHKeyword\">struct</span></div><div class=\"CPName\">GenericList_t</div></div></div><div class=\"TTSummary\">The struct that creates and performs operations on objects of type GenericList.</div></div>",20:"<div class=\"NDToolTip TVariable LC\"><div id=\"NDPrototype20\" class=\"NDPrototype\"><div class=\"PSection PPlainSection\"><span class=\"SHKeyword\">const</span> Class *elementClass</div></div><div class=\"TTSummary\">A pointer to the element class so that elements will be created and destroyed properly.</div></div>",22:"<div class=\"NDToolTip TClass LC\"><div class=\"NDClassPrototype\" id=\"NDClassPrototype22\"><div class=\"CPEntry TClass Current\"><div class=\"CPModifiers\"><span class=\"SHKeyword\">typedef</span> <span class=\"SHKeyword\">struct</span></div><div class=\"CPName\">GenericList</div></div></div><div class=\"TTSummary\">The struct that represents a GenericList.</div></div>",68:"<div class=\"NDToolTip TStruct LC\"><div class=\"NDClassPrototype\" id=\"NDClassPrototype68\"><div class=\"CPEntry TStruct Current\"><div class=\"CPModifiers\"><span class=\"SHKeyword\">typedef</span> <span class=\"SHKeyword\">struct</span></div><div class=\"CPName\">Class</div></div></div><div class=\"TTSummary\">The struct that defines various memory related operations related to objects.&nbsp; Each struct of &lt;type&gt;_t needs to have a Class struct named &quot;class&quot; for the above macros to work.</div></div>",93:"<div class=\"NDToolTip TFunction LC\"><div id=\"NDPrototype93\" class=\"NDPrototype WideForm\"><div class=\"PSection PParameterSection CStyle\"><table><tr><td class=\"PBeforeParameters\"><span class=\"SHKeyword\">bool</span> (</td><td class=\"PParametersParentCell\"><table class=\"PParameters\"><tr><td class=\"PSymbols first\">*</td><td class=\"PName last\">removeBetween</td></tr></table></td><td class=\"PAfterParameters\">)(GenericList *self, <span class=\"SHKeyword\">const int</span> startIndex, <span class=\"SHKeyword\">const int</span> endIndex)</td></tr></table></div></div><div class=\"TTSummary\">Removes the items between the supplied indexes. The destructor in the GenericList.elementClass struct will be called for each element that is deleted.</div></div>",95:"<div class=\"NDToolTip TFunction LC\"><div id=\"NDPrototype95\" class=\"NDPrototype WideForm\"><div class=\"PSection PParameterSection CStyle\"><table><tr><td class=\"PBeforeParameters\"><span class=\"SHKeyword\">bool</span> (</td><td class=\"PParametersParentCell\"><table class=\"PParameters\"><tr><td class=\"PSymbols first\">*</td><td class=\"PName last\">clear</td></tr></table></td><td class=\"PAfterParameters\">)(GenericList *self)</td></tr></table></div></div><div class=\"TTSummary\">Removes all elements from the list and frees the underlying memory. The destructor in the GenericList.elementClass struct will be called for each element that is deleted.</div></div>"});