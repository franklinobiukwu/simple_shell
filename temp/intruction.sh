#!/bin/bash
ls --color=auto -la
echo "Enter a file name"
read filename
touch $filename
echo "File has been created"
ls --color=auto -la
echo "Do you want to delete created file? Type \"yes\" or \"no\""
read response
if [ "$response" = "yes" ]; then
	rm $filename
	ls --color=auto -la
elif [ "$response" = "no" ]; then
	ls --color=auto -la
fi
