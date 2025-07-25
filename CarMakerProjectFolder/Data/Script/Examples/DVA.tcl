##
## DVA.tcl  --  Direct Variable Access
## CarMaker 14.0 ScriptControl Example - IPG Automotive GmbH (www.ipg-automotive.com)
##
## This example shows how to set the value of a variable using DVA.
## The functions introduced are:
##
## DVAWrite <Name> <Value> <Duration> <Mode> ...
##     <Name>     Quantity name
##     <Value>    New quantity value
##     <Duration> Duration in milliseconds 
##     <Mode>     One of Abs, Off, Fac, AbsRamp, ...; default Abs(olute Value)
##     DVAWrite sets the value of the specified quantity using DVA
##
## DVAReleaseQuants
##     Releases all quantities from DVA control. A quantity won't be reset,
##     so unless it is modified by some internal function it will keep the
##     value last given by DVA.
##

# Subscribe to all needed quantities
QuantSubscribe DM.Steer.Ang   ;# implicitly includes Time


Log "* Load Test Run"
LoadTestRun "Examples/VehicleDynamics/Braking/Braking"

Log "* Start Simulation..."
StartSim
WaitForStatus running

Sleep 5000
Log "  Wheel turned to Angle 2 rad."
DVAWrite DM.Steer.Ang 2 5000 Abs

WaitForStatus idle

Log ""
Log "  +++++++++++++++++++++++++++++++++++++++++++++"
Log "  Car went off the road at: "
Log "  Time                 =  $Qu(Time) seconds"
Log "  Steering Wheel Angle =  2 rad"
Log "  +++++++++++++++++++++++++++++++++++++++++++++\n"

DVAReleaseQuants
