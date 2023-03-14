#!/bin/bash  
echo "converting test files to mil..."
cat basic.ppc | parser > basic.mil
cat add.ppc | parser > add.mil
cat math.ppc | parser > math.mil
cat arrayTest.ppc | parser > array.mil
cat function.ppc | parser > function.mil
echo "done converting to .mil files"