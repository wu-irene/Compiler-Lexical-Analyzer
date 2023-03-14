#!/bin/bash  
echo "converting test files to mil..."
cat loop.ppc | parser > loop.mil
cat ifelse.ppc | parser > ifelse.mil
cat break.ppc | parser > break.mil
cat nested_loop.ppc | parser > nested_loop.mil
echo "done converting to .mil files\n"
echo "Running mil_run loop.mil..."
mil_run loop.mil
echo "Running mil_run ifelse.mil..."
mil_run ifelse.mil
echo "Running mil_run break.mil..."
mil_run break.mil
echo "Running mil_run nested_loop.mil..."
mil_run nested_loop.mil
