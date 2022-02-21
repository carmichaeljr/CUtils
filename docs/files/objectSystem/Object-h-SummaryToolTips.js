﻿NDSummary.OnToolTipsLoaded("File:objectSystem/Object.h",{80:"<div class=\"NDToolTip TStruct LC\"><div class=\"NDClassPrototype\" id=\"NDClassPrototype80\"><div class=\"CPEntry TStruct Current\"><div class=\"CPModifiers\"><span class=\"SHKeyword\">typedef</span> <span class=\"SHKeyword\">struct</span></div><div class=\"CPName\">Class</div></div></div><div class=\"TTSummary\">The struct that defines various memory related operations related to objects.&nbsp; Each struct of &lt;type&gt;_t needs to have a Class struct named &quot;class&quot; for the above macros to work.</div></div>",82:"<div class=\"NDToolTip TFunction LC\"><div id=\"NDPrototype82\" class=\"NDPrototype WideForm\"><div class=\"PSection PParameterSection CStyle\"><table><tr><td class=\"PBeforeParameters\"><span class=\"SHKeyword\">void</span>* (</td><td class=\"PParametersParentCell\"><table class=\"PParameters\"><tr><td class=\"PSymbols first\">*</td><td class=\"PName last\">allocator</td></tr></table></td><td class=\"PAfterParameters\">)(size_t size)</td></tr></table></div></div><div class=\"TTSummary\">Responsible for allocating space for the object.</div></div>",83:"<div class=\"NDToolTip TFunction LC\"><div id=\"NDPrototype83\" class=\"NDPrototype WideForm\"><div class=\"PSection PParameterSection CStyle\"><table><tr><td class=\"PBeforeParameters\"><span class=\"SHKeyword\">void</span> (</td><td class=\"PParametersParentCell\"><table class=\"PParameters\"><tr><td class=\"PSymbols first\">*</td><td class=\"PName last\">constructor</td></tr></table></td><td class=\"PAfterParameters\">)(<span class=\"SHKeyword\">void</span> *obj)</td></tr></table></div></div><div class=\"TTSummary\">Responsible for initializing an already allocated object.</div></div>",84:"<div class=\"NDToolTip TFunction LC\"><div id=\"NDPrototype84\" class=\"NDPrototype WideForm\"><div class=\"PSection PParameterSection CStyle\"><table><tr><td class=\"PBeforeParameters\"><span class=\"SHKeyword\">void</span>* (</td><td class=\"PParametersParentCell\"><table class=\"PParameters\"><tr><td class=\"PSymbols first\">*</td><td class=\"PName last\">copyConstructor</td></tr></table></td><td class=\"PAfterParameters\">)(<span class=\"SHKeyword\">void</span> *obj, <span class=\"SHKeyword\">const void</span> * <span class=\"SHKeyword\">const</span> other, size_t size)</td></tr></table></div></div><div class=\"TTSummary\">Responsible for creating a clone of another object, given already allocated memory.</div></div>",85:"<div class=\"NDToolTip TFunction LC\"><div id=\"NDPrototype85\" class=\"NDPrototype WideForm\"><div class=\"PSection PParameterSection CStyle\"><table><tr><td class=\"PBeforeParameters\"><span class=\"SHKeyword\">int</span> (</td><td class=\"PParametersParentCell\"><table class=\"PParameters\"><tr><td class=\"PSymbols first\">*</td><td class=\"PName last\">comparator</td></tr></table></td><td class=\"PAfterParameters\">)(<span class=\"SHKeyword\">const void</span> *first, <span class=\"SHKeyword\">const void</span> *second, size_t size)</td></tr></table></div></div><div class=\"TTSummary\">Responsible for comparing two objects of the same type.</div></div>",86:"<div class=\"NDToolTip TFunction LC\"><div id=\"NDPrototype86\" class=\"NDPrototype WideForm\"><div class=\"PSection PParameterSection CStyle\"><table><tr><td class=\"PBeforeParameters\"><span class=\"SHKeyword\">void</span> (</td><td class=\"PParametersParentCell\"><table class=\"PParameters\"><tr><td class=\"PSymbols first\">*</td><td class=\"PName last\">destructor</td></tr></table></td><td class=\"PAfterParameters\">)(<span class=\"SHKeyword\">void</span> *obj)</td></tr></table></div></div><div class=\"TTSummary\">Responsible for deleting and freeing memory allocated for the given object.</div></div>",151:"<div class=\"NDToolTip TMacro LC\"><div id=\"NDPrototype151\" class=\"NDPrototype WideForm\"><div class=\"PSection PParameterSection CStyle\"><table><tr><td class=\"PBeforeParameters\"><span class=\"SHKeyword\">new</span>(</td><td class=\"PParametersParentCell\"><table class=\"PParameters\"><tr><td class=\"PName first\">type,</td><td></td><td class=\"last\"></td></tr><tr><td class=\"PName first\">obj</td><td class=\"PDefaultValueSeparator\">&nbsp;=&nbsp;</td><td class=\"PDefaultValue last\">NULL</td></tr></table></td><td class=\"PAfterParameters\">)</td></tr></table></div></div><div class=\"TTSummary\">New is a function-macro that, given a type, creates a new object of that type.&nbsp; This macro is overloaded with a default parameter.&nbsp; If obj is NULL then memory will be allocated for the new object. If obj is not NULL then obj is treated as a pointer to memory already allocated for the new object.</div></div>",152:"<div class=\"NDToolTip TMacro LC\"><div id=\"NDPrototype152\" class=\"NDPrototype WideForm\"><div class=\"PSection PParameterSection CStyle\"><table><tr><td class=\"PBeforeParameters\">newS(</td><td class=\"PParametersParentCell\"><table class=\"PParameters\"><tr><td class=\"PName first last\">type,</td></tr><tr><td class=\"PName first last\">objName</td></tr></table></td><td class=\"PAfterParameters\">)</td></tr></table></div></div><div class=\"TTSummary\">Creates an object on the stack instead of the heap. Note that this can already be done with new. newS just supplies a short hand notation for doing so. The below code examples show how to use newS.</div></div>",153:"<div class=\"NDToolTip TMacro LC\"><div id=\"NDPrototype153\" class=\"NDPrototype WideForm\"><div class=\"PSection PParameterSection CStyle\"><table><tr><td class=\"PBeforeParameters\">newFromClass(</td><td class=\"PParametersParentCell\"><table class=\"PParameters\"><tr><td class=\"PName first\">type,</td><td></td><td class=\"last\"></td></tr><tr><td class=\"PName first\">obj</td><td class=\"PDefaultValueSeparator\">&nbsp;=&nbsp;</td><td class=\"PDefaultValue last\">NULL</td></tr></table></td><td class=\"PAfterParameters\">)</td></tr></table></div></div><div class=\"TTSummary\">A function-macro that, given a class, and object size, creates a new object of that type.&nbsp; This macro is overloaded with a default parameter.&nbsp; If obj is NULL then memory will be allocated for the new object. If obj is not NULL then obj is treated as a pointer to memory already allocated for the new object.</div></div>",154:"<div class=\"NDToolTip TMacro LC\"><div id=\"NDPrototype154\" class=\"NDPrototype WideForm\"><div class=\"PSection PParameterSection CStyle\"><table><tr><td class=\"PBeforeParameters\">copy(</td><td class=\"PParametersParentCell\"><table class=\"PParameters\"><tr><td class=\"PName first\">type,</td><td></td><td class=\"last\"></td></tr><tr><td class=\"PName first\">obj</td><td class=\"PDefaultValueSeparator\">&nbsp;=&nbsp;</td><td class=\"PDefaultValue last\">NULL,</td></tr><tr><td class=\"PName first\">other</td><td></td><td class=\"last\"></td></tr></table></td><td class=\"PAfterParameters\">)</td></tr></table></div></div><div class=\"TTSummary\">Copy is a function-macro that, given a type and a preexisting object, creates a copy of the object.&nbsp; This macro is overloaded with a default parameter.&nbsp; If obj is NULL then memory will be allocated for the new object. If obj is not NULL then obj is treated as a pointer to memory already allocated for the new object.</div></div>",155:"<div class=\"NDToolTip TMacro LC\"><div id=\"NDPrototype155\" class=\"NDPrototype WideForm\"><div class=\"PSection PParameterSection CStyle\"><table><tr><td class=\"PBeforeParameters\"><span class=\"SHKeyword\">delete</span>(</td><td class=\"PParametersParentCell\"><table class=\"PParameters\"><tr><td class=\"PName first\">type,</td><td></td><td class=\"last\"></td></tr><tr><td class=\"PName first\">obj,</td><td></td><td class=\"last\"></td></tr><tr><td class=\"PName first\">freeObj</td><td class=\"PDefaultValueSeparator\">&nbsp;=&nbsp;</td><td class=\"PDefaultValue last\"><span class=\"SHKeyword\">true</span></td></tr></table></td><td class=\"PAfterParameters\">)</td></tr></table></div></div><div class=\"TTSummary\">Delete is a function-macro that, given a type and a preexisting object, deletes the object.&nbsp; This macro is overloaded through defining a default parameter.&nbsp; If freeObj is true then the memory allocated to the object will be freed. If obj is false then the memory allocated for the object will not be freed.</div></div>",156:"<div class=\"NDToolTip TMacro LC\"><div id=\"NDPrototype156\" class=\"NDPrototype WideForm\"><div class=\"PSection PParameterSection CStyle\"><table><tr><td class=\"PBeforeParameters\">deleteFromClass(</td><td class=\"PParametersParentCell\"><table class=\"PParameters\"><tr><td class=\"PName first\">class,</td><td></td><td class=\"last\"></td></tr><tr><td class=\"PName first\">size,</td><td></td><td class=\"last\"></td></tr><tr><td class=\"PName first\">obj,</td><td></td><td class=\"last\"></td></tr><tr><td class=\"PName first\">freeObj</td><td class=\"PDefaultValueSeparator\">&nbsp;=&nbsp;</td><td class=\"PDefaultValue last\"><span class=\"SHKeyword\">true</span></td></tr></table></td><td class=\"PAfterParameters\">)</td></tr></table></div></div><div class=\"TTSummary\">Delete is a function-macro that, given a class, preexisting object, and the size of the preexsisting object, deletes the object.&nbsp; This macro is overloaded through defining a default parameter.&nbsp; If freeObj is true then the memory allocated to the object will be freed. If obj is false then the memory allocated for the object will not be freed.</div></div>",171:"<div class=\"NDToolTip TMacro LC\"><div id=\"NDPrototype171\" class=\"NDPrototype WideForm\"><div class=\"PSection PParameterSection CStyle\"><table><tr><td class=\"PBeforeParameters\">deleteS(</td><td class=\"PParametersParentCell\"><table class=\"PParameters\"><tr><td class=\"PName first last\">type,</td></tr><tr><td class=\"PName first last\">objName</td></tr></table></td><td class=\"PAfterParameters\">)</td></tr></table></div></div><div class=\"TTSummary\">Deletes an object allocated on the stack. Note that this can already be done with delete. deleteS just supplies a short hand notation for doing so. The below code examples show how to use deleteS.</div></div>",172:"<div class=\"NDToolTip TMacro LC\"><div id=\"NDPrototype172\" class=\"NDPrototype WideForm\"><div class=\"PSection PParameterSection CStyle\"><table><tr><td class=\"PBeforeParameters\">equals(</td><td class=\"PParametersParentCell\"><table class=\"PParameters\"><tr><td class=\"PName first last\">type,</td></tr><tr><td class=\"PName first last\">obj1,</td></tr><tr><td class=\"PName first last\">obj2</td></tr></table></td><td class=\"PAfterParameters\">)</td></tr></table></div></div><div class=\"TTSummary\">Equals is a function-macro that, given a type and two preexisting objects, compares the two objects.</div></div>",173:"<div class=\"NDToolTip TMacro LC\"><div id=\"NDPrototype173\" class=\"NDPrototype WideForm\"><div class=\"PSection PParameterSection CStyle\"><table><tr><td class=\"PBeforeParameters\">equalsFromClass(</td><td class=\"PParametersParentCell\"><table class=\"PParameters\"><tr><td class=\"PName first last\">class,</td></tr><tr><td class=\"PName first last\">size,</td></tr><tr><td class=\"PName first last\">obj1,</td></tr><tr><td class=\"PName first last\">obj2</td></tr></table></td><td class=\"PAfterParameters\">)</td></tr></table></div></div><div class=\"TTSummary\">Equals is a function-macro that, given a type and two preexisting objects, compares the two objects.</div></div>",174:"<div class=\"NDToolTip TMacro LC\"><div id=\"NDPrototype174\" class=\"NDPrototype WideForm\"><div class=\"PSection PParameterSection CStyle\"><table><tr><td class=\"PBeforeParameters\">DEFAULT_CLASS {</td><td class=\"PParametersParentCell\"><table class=\"PParameters\"><tr><td class=\"PSymbols first\">.</td><td class=\"PName\">allocator</td><td class=\"PDefaultValueSeparator\">&nbsp;=&nbsp;</td><td class=\"PDefaultValue last\">malloc,</td></tr><tr><td class=\"PSymbols first\">.</td><td class=\"PName\">constructor</td><td class=\"PDefaultValueSeparator\">&nbsp;=&nbsp;</td><td class=\"PDefaultValue last\">constructor,</td></tr><tr><td class=\"PSymbols first\">.</td><td class=\"PName\">copyConstructor</td><td class=\"PDefaultValueSeparator\">&nbsp;=&nbsp;</td><td class=\"PDefaultValue last\">memcpy,</td></tr><tr><td class=\"PSymbols first\">.</td><td class=\"PName\">comparator</td><td class=\"PDefaultValueSeparator\">&nbsp;=&nbsp;</td><td class=\"PDefaultValue last\">memcmp,</td></tr><tr><td class=\"PSymbols first\">.</td><td class=\"PName\">destructor</td><td class=\"PDefaultValueSeparator\">&nbsp;=&nbsp;</td><td class=\"PDefaultValue last\">destructor,</td></tr><tr><td class=\"first\"></td><td></td><td></td><td class=\"last\"></td></tr></table></td><td class=\"PAfterParameters\">}</td></tr></table></div></div><div class=\"TTSummary\">DEFAULT_CLASS is a macro that defines default allocator, copyConstructor, and comparator functions.&nbsp; Use this macro when the only functions you wish to change from default in the Class struct are the constructor and destructor.</div></div>",175:"<div class=\"NDToolTip TMacro LC\"><div id=\"NDPrototype175\" class=\"NDPrototype WideForm\"><div class=\"PSection PParameterSection CStyle\"><table><tr><td class=\"PBeforeParameters\">ALLOC_ONLY_DEFAULT_CLASS {</td><td class=\"PParametersParentCell\"><table class=\"PParameters\"><tr><td class=\"PSymbols first\">.</td><td class=\"PName\">allocator</td><td class=\"PDefaultValueSeparator\">&nbsp;=&nbsp;</td><td class=\"PDefaultValue last\">malloc,</td></tr><tr><td class=\"PSymbols first\">.</td><td class=\"PName\">constructor</td><td class=\"PDefaultValueSeparator\">&nbsp;=&nbsp;</td><td class=\"PDefaultValue last\">constructor,</td></tr><tr><td class=\"PSymbols first\">.</td><td class=\"PName\">copyConstructor</td><td class=\"PDefaultValueSeparator\">&nbsp;=&nbsp;</td><td class=\"PDefaultValue last\">copyConstructor,</td></tr><tr><td class=\"PSymbols first\">.</td><td class=\"PName\">comparator</td><td class=\"PDefaultValueSeparator\">&nbsp;=&nbsp;</td><td class=\"PDefaultValue last\">comparator,</td></tr><tr><td class=\"PSymbols first\">.</td><td class=\"PName\">destructor</td><td class=\"PDefaultValueSeparator\">&nbsp;=&nbsp;</td><td class=\"PDefaultValue last\">destructor,</td></tr><tr><td class=\"first\"></td><td></td><td></td><td class=\"last\"></td></tr></table></td><td class=\"PAfterParameters\">}</td></tr></table></div></div><div class=\"TTSummary\">ALLOC_ONLY_DEFAULT_CLASS is a macro that defines only a default allocator function.&nbsp; Use this macro when the only functions you wish to change from default in the Class struct are the constructor, copyConstructor, comparator, and destructor.</div></div>",176:"<div class=\"NDToolTip TMacro LC\"><div id=\"NDPrototype176\" class=\"NDPrototype WideForm\"><div class=\"PSection PParameterSection CStyle\"><table><tr><td class=\"PBeforeParameters\">SINGLETON_CLASS {</td><td class=\"PParametersParentCell\"><table class=\"PParameters\"><tr><td class=\"PSymbols first\">.</td><td class=\"PName\">allocator</td><td class=\"PDefaultValueSeparator\">&nbsp;=&nbsp;</td><td class=\"PDefaultValue last\">allocator,</td></tr><tr><td class=\"PSymbols first\">.</td><td class=\"PName\">constructor</td><td class=\"PDefaultValueSeparator\">&nbsp;=&nbsp;</td><td class=\"PDefaultValue last\">constructor,</td></tr><tr><td class=\"PSymbols first\">.</td><td class=\"PName\">copyConstructor</td><td class=\"PDefaultValueSeparator\">&nbsp;=&nbsp;</td><td class=\"PDefaultValue last\">NULL,</td></tr><tr><td class=\"PSymbols first\">.</td><td class=\"PName\">comparator</td><td class=\"PDefaultValueSeparator\">&nbsp;=&nbsp;</td><td class=\"PDefaultValue last\">NULL,</td></tr><tr><td class=\"PSymbols first\">.</td><td class=\"PName\">destructor</td><td class=\"PDefaultValueSeparator\">&nbsp;=&nbsp;</td><td class=\"PDefaultValue last\">destructor,</td></tr><tr><td class=\"first\"></td><td></td><td></td><td class=\"last\"></td></tr></table></td><td class=\"PAfterParameters\">}</td></tr></table></div></div><div class=\"TTSummary\">SINGLETON_CLASS is a macro that defines class functions to support singleton creation. Note that the class needs to keep track of weather or not it has been initialized already or not.&nbsp; Use this macro when the only functions you wish to change from default in the Class struct are the allocator, constructor, and destructor.</div></div>"});