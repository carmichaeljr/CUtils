﻿NDSummary.OnToolTipsLoaded("CClass:ComparisonOperators",{115:"<div class=\"NDToolTip TStruct LC\"><div class=\"NDClassPrototype\" id=\"NDClassPrototype115\"><div class=\"CPEntry TStruct Current\"><div class=\"CPModifiers\"><span class=\"SHKeyword\">typedef</span> <span class=\"SHKeyword\">struct</span></div><div class=\"CPName\">ComparisonOperators</div></div></div><div class=\"TTSummary\">The struct that defines various equality related operations related to objects.&nbsp; Each struct of &lt;type&gt;_t needs to have a ComparisonOperator struct named &quot;comparisonOperators&quot; for the above macros to work.</div></div>",117:"<div class=\"NDToolTip TFunction LC\"><div id=\"NDPrototype117\" class=\"NDPrototype WideForm\"><div class=\"PSection PParameterSection CStyle\"><table><tr><td class=\"PBeforeParameters\"><span class=\"SHKeyword\">bool</span> (</td><td class=\"PParametersParentCell\"><table class=\"PParameters\"><tr><td class=\"PSymbols first\">*</td><td class=\"PName last\">eqOperator</td></tr></table></td><td class=\"PAfterParameters\">)(<span class=\"SHKeyword\">const void</span> * <span class=\"SHKeyword\">const</span> first, <span class=\"SHKeyword\">const void</span> * <span class=\"SHKeyword\">const</span> second, size_t size)</td></tr></table></div></div><div class=\"TTSummary\">Defines if two objects of the same type are considered equal or not</div></div>",136:"<div class=\"NDToolTip TFunction LC\"><div id=\"NDPrototype136\" class=\"NDPrototype WideForm\"><div class=\"PSection PParameterSection CStyle\"><table><tr><td class=\"PBeforeParameters\"><span class=\"SHKeyword\">bool</span> (</td><td class=\"PParametersParentCell\"><table class=\"PParameters\"><tr><td class=\"PSymbols first\">*</td><td class=\"PName last\">neqOperator</td></tr></table></td><td class=\"PAfterParameters\">)(<span class=\"SHKeyword\">const void</span> * <span class=\"SHKeyword\">const</span> first, <span class=\"SHKeyword\">const void</span> * <span class=\"SHKeyword\">const</span> second, size_t size)</td></tr></table></div></div><div class=\"TTSummary\">Defines if two objects of the same type are considered not equal</div></div>",137:"<div class=\"NDToolTip TFunction LC\"><div id=\"NDPrototype137\" class=\"NDPrototype WideForm\"><div class=\"PSection PParameterSection CStyle\"><table><tr><td class=\"PBeforeParameters\"><span class=\"SHKeyword\">bool</span> (</td><td class=\"PParametersParentCell\"><table class=\"PParameters\"><tr><td class=\"PSymbols first\">*</td><td class=\"PName last\">gtOperator</td></tr></table></td><td class=\"PAfterParameters\">)(<span class=\"SHKeyword\">const void</span> * <span class=\"SHKeyword\">const</span> first, <span class=\"SHKeyword\">const void</span> * <span class=\"SHKeyword\">const</span> second, size_t size)</td></tr></table></div></div><div class=\"TTSummary\">Defines if one object is greater than another object of the same type</div></div>",138:"<div class=\"NDToolTip TFunction LC\"><div id=\"NDPrototype138\" class=\"NDPrototype WideForm\"><div class=\"PSection PParameterSection CStyle\"><table><tr><td class=\"PBeforeParameters\"><span class=\"SHKeyword\">bool</span> (</td><td class=\"PParametersParentCell\"><table class=\"PParameters\"><tr><td class=\"PSymbols first\">*</td><td class=\"PName last\">ltOperator</td></tr></table></td><td class=\"PAfterParameters\">)(<span class=\"SHKeyword\">const void</span> * <span class=\"SHKeyword\">const</span> first, <span class=\"SHKeyword\">const void</span> * <span class=\"SHKeyword\">const</span> second, size_t size)</td></tr></table></div></div><div class=\"TTSummary\">Defines if one object is less than another object of the same type</div></div>",139:"<div class=\"NDToolTip TFunction LC\"><div id=\"NDPrototype139\" class=\"NDPrototype WideForm\"><div class=\"PSection PParameterSection CStyle\"><table><tr><td class=\"PBeforeParameters\"><span class=\"SHKeyword\">bool</span> (</td><td class=\"PParametersParentCell\"><table class=\"PParameters\"><tr><td class=\"PSymbols first\">*</td><td class=\"PName last\">gteOperator</td></tr></table></td><td class=\"PAfterParameters\">)(<span class=\"SHKeyword\">const void</span> * <span class=\"SHKeyword\">const</span> first, <span class=\"SHKeyword\">const void</span> * <span class=\"SHKeyword\">const</span> second, size_t size)</td></tr></table></div></div><div class=\"TTSummary\">Defines if one object is greater than or equal to another object of the same type</div></div>",140:"<div class=\"NDToolTip TFunction LC\"><div id=\"NDPrototype140\" class=\"NDPrototype WideForm\"><div class=\"PSection PParameterSection CStyle\"><table><tr><td class=\"PBeforeParameters\"><span class=\"SHKeyword\">bool</span> (</td><td class=\"PParametersParentCell\"><table class=\"PParameters\"><tr><td class=\"PSymbols first\">*</td><td class=\"PName last\">lteOperator</td></tr></table></td><td class=\"PAfterParameters\">)(<span class=\"SHKeyword\">const void</span> * <span class=\"SHKeyword\">const</span> first, <span class=\"SHKeyword\">const void</span> * <span class=\"SHKeyword\">const</span> second, size_t size)</td></tr></table></div></div><div class=\"TTSummary\">Defines if one object is less than or equal to another object of the same type</div></div>",123:"<div class=\"NDToolTip TMacro LC\"><div id=\"NDPrototype123\" class=\"NDPrototype WideForm\"><div class=\"PSection PParameterSection CStyle\"><table><tr><td class=\"PBeforeParameters\">eq(</td><td class=\"PParametersParentCell\"><table class=\"PParameters\"><tr><td class=\"PName first last\">type,</td></tr><tr><td class=\"PName first last\">obj1,</td></tr><tr><td class=\"PName first last\">obj2</td></tr></table></td><td class=\"PAfterParameters\">)</td></tr></table></div></div><div class=\"TTSummary\">Equals is a function-macro that, given a type and two preexisting objects, compares the two objects.</div></div>",124:"<div class=\"NDToolTip TMacro LC\"><div id=\"NDPrototype124\" class=\"NDPrototype WideForm\"><div class=\"PSection PParameterSection CStyle\"><table><tr><td class=\"PBeforeParameters\">neq(</td><td class=\"PParametersParentCell\"><table class=\"PParameters\"><tr><td class=\"PName first last\">type,</td></tr><tr><td class=\"PName first last\">obj1,</td></tr><tr><td class=\"PName first last\">obj2</td></tr></table></td><td class=\"PAfterParameters\">)</td></tr></table></div></div><div class=\"TTSummary\">A function-macro that, given a type and two preexisting objects, compares the two objects.</div></div>",177:"<div class=\"NDToolTip TMacro LC\"><div id=\"NDPrototype177\" class=\"NDPrototype WideForm\"><div class=\"PSection PParameterSection CStyle\"><table><tr><td class=\"PBeforeParameters\">gt(</td><td class=\"PParametersParentCell\"><table class=\"PParameters\"><tr><td class=\"PName first last\">type,</td></tr><tr><td class=\"PName first last\">obj1,</td></tr><tr><td class=\"PName first last\">obj2</td></tr></table></td><td class=\"PAfterParameters\">)</td></tr></table></div></div><div class=\"TTSummary\">A function-macro that, given a type and two preexisting objects, compares the two objects.</div></div>",178:"<div class=\"NDToolTip TMacro LC\"><div id=\"NDPrototype178\" class=\"NDPrototype WideForm\"><div class=\"PSection PParameterSection CStyle\"><table><tr><td class=\"PBeforeParameters\">lt(</td><td class=\"PParametersParentCell\"><table class=\"PParameters\"><tr><td class=\"PName first last\">type,</td></tr><tr><td class=\"PName first last\">obj1,</td></tr><tr><td class=\"PName first last\">obj2</td></tr></table></td><td class=\"PAfterParameters\">)</td></tr></table></div></div><div class=\"TTSummary\">A function-macro that, given a type and two preexisting objects, compares the two objects.</div></div>",179:"<div class=\"NDToolTip TMacro LC\"><div id=\"NDPrototype179\" class=\"NDPrototype WideForm\"><div class=\"PSection PParameterSection CStyle\"><table><tr><td class=\"PBeforeParameters\">gte(</td><td class=\"PParametersParentCell\"><table class=\"PParameters\"><tr><td class=\"PName first last\">type,</td></tr><tr><td class=\"PName first last\">obj1,</td></tr><tr><td class=\"PName first last\">obj2</td></tr></table></td><td class=\"PAfterParameters\">)</td></tr></table></div></div><div class=\"TTSummary\">A function-macro that, given a type and two preexisting objects, compares the two objects.</div></div>",180:"<div class=\"NDToolTip TMacro LC\"><div id=\"NDPrototype180\" class=\"NDPrototype WideForm\"><div class=\"PSection PParameterSection CStyle\"><table><tr><td class=\"PBeforeParameters\">lte(</td><td class=\"PParametersParentCell\"><table class=\"PParameters\"><tr><td class=\"PName first last\">type,</td></tr><tr><td class=\"PName first last\">obj1,</td></tr><tr><td class=\"PName first last\">obj2</td></tr></table></td><td class=\"PAfterParameters\">)</td></tr></table></div></div><div class=\"TTSummary\">A function-macro that, given a type and two preexisting objects, compares the two objects.</div></div>",181:"<div class=\"NDToolTip TMacro LC\"><div id=\"NDPrototype181\" class=\"NDPrototype WideForm\"><div class=\"PSection PParameterSection CStyle\"><table><tr><td class=\"PBeforeParameters\">DEFAULT_COMPARISON_OPERATORS {</td><td class=\"PParametersParentCell\"><table class=\"PParameters\"><tr><td class=\"PSymbols first\">.</td><td class=\"PName\">eqOperator</td><td class=\"PDefaultValueSeparator\">&nbsp;=&nbsp;</td><td class=\"PDefaultValue last\">eqOperator,</td></tr><tr><td class=\"PSymbols first\">.</td><td class=\"PName\">neqOperator</td><td class=\"PDefaultValueSeparator\">&nbsp;=&nbsp;</td><td class=\"PDefaultValue last\">neqOperator,</td></tr><tr><td class=\"PSymbols first\">.</td><td class=\"PName\">gtOperator</td><td class=\"PDefaultValueSeparator\">&nbsp;=&nbsp;</td><td class=\"PDefaultValue last\">gtOperator,</td></tr><tr><td class=\"PSymbols first\">.</td><td class=\"PName\">ltOperator</td><td class=\"PDefaultValueSeparator\">&nbsp;=&nbsp;</td><td class=\"PDefaultValue last\">ltOperator,</td></tr><tr><td class=\"PSymbols first\">.</td><td class=\"PName\">gteOperator</td><td class=\"PDefaultValueSeparator\">&nbsp;=&nbsp;</td><td class=\"PDefaultValue last\">gteOperator,</td></tr><tr><td class=\"PSymbols first\">.</td><td class=\"PName\">lteOperator</td><td class=\"PDefaultValueSeparator\">&nbsp;=&nbsp;</td><td class=\"PDefaultValue last\">lteOperator,</td></tr><tr><td class=\"first\"></td><td></td><td></td><td class=\"last\"></td></tr></table></td><td class=\"PAfterParameters\">}</td></tr></table></div></div><div class=\"TTSummary\">DEFAULT_COMPARISON_OPERATORS is a macro that defines default comparison functions for a class.</div></div>"});