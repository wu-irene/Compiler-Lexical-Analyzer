#!/bin/bash  
echo "converting test files to mil..."
cat basic.ppc | parser > basic.mil
cat add.ppc | parser > add.ppc
cat math.ppc | parser > math.ppc
cat arrayTest.ppc | parser > array.mil
cat function.ppc | parser > function.mil
echo "done converting to .mil files"