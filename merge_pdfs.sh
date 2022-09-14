#!/bin/bash

export PROBLEMSJSON=$(cat .problems.json)
PROBLEMS=$(python3 -c 'import json, os; print(" ".join(json.loads(os.environ.get("PROBLEMSJSON"))))')

MERGECMD="pdfunite "
for prob in $PROBLEMS; do
	if [ -f "p${prob}/statement/index.pdf" ]; then
		MERGECMD="$MERGECMD p${prob}/statement/index.pdf"
	fi
done
MERGECMD="$MERGECMD pA/attachments/problems.pdf"
echo $MERGECMD
mkdir -p pA/attachments
$MERGECMD
