#!/bin/bash
echo "Hello from GitHub Actions on Linux!" 
cd CarMakerProjectFolder/Data/TestRun || exit 1
./Run_headless.sh > CarMakerlogs.txt 2>&1

