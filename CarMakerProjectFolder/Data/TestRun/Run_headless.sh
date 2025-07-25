#!/bin/bash

# Get the directory where the script is located
SCRIPT_DIR="$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)"

# Go two levels up to get the project root
PROJECT_ROOT="$(cd "$SCRIPT_DIR/../.." && pwd)"

for file in "$PROJECT_ROOT/Startupfiles"/*
do
  "$PROJECT_ROOT/src/CarMaker.linux64" "$file" -v -screen -dstore
done

