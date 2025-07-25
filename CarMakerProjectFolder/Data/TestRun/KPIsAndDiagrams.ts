#INFOFILE1.1 (UTF-8) - Do not remove this line!
FileIdent = CarMaker-TestSeries 14
FileCreator = CarMaker Office 14.0 TEMPLATE
Description:
	In this Test Series, variations of a braking Test Run are executed. Typical criteria are calculated and evaluated. Diagrams are generated.
LastChange = 2024-10-09 14:34:26 fh
StartTime = 2018-10-08 09:41:26
EndTime = 2018-10-08 09:41:36
ReportTemplate =
Step.0 = Settings
Step.0.Name = Global Settings
Step.1 = TestRun
Step.1.Name = Examples/BasicFunctions/TestAutomation/TestManager/Runs/Braking
Step.1.Param.0 = Brake NValue
Step.1.Char.0.Name = Brake Distance Calculation
Step.1.Char.0.Description:
	A new quantity "BrakeDist" is initialized. It records the distance travelled by the test car after the braking maneuver started.
Step.1.Char.0.Identifier = BrakeDist
Step.1.Char.0.Unit = m
Step.1.Char.0.Param.0 = RTexpr {(first() ? Qu::BrakeDist=0); DM.Long.StepIdx>0 ? BrakeDist=Delta2Ev(Car.Road.sRoad, change(DM.Brake), Car.v <=0.01)}
Step.1.Crit.0.Name = Brake Distance
Step.1.Crit.0.Description:
	Test Run evaluation is carried out on the basis of Brake Distance. Test Run is considered good if Brake Distance is below treshold.
Step.1.Crit.0.Good = [get BrakeDist]  < 27.0
Step.1.Crit.0.Warn = [get BrakeDist]  >= 27.0 && [get BrakeDist] < 32.0
Step.1.Crit.0.Bad = [get BrakeDist]  >= 32.0
Step.1.Diag.0.Name = Brake Distance vs Time
Step.1.Diag.0.Type = Vertical Bar Diagram
Step.1.Diag.0.Mode = Characteristic vs Variation
Step.1.Diag.0.VarOpt = 1
Step.1.Diag.0.Grid = None
Step.1.Diag.0.NAxes = 1
Step.1.Diag.0.RefFile =
Step.1.Diag.0.Pic =
Step.1.Diag.0.Param1.0 = Auto {} {} {}
Step.1.Diag.0.Param1.1 = Manual 0 {} {Brake Distance}
Step.1.Diag.0.Param2.0 = Variation {} {} {}
Step.1.Diag.0.Param2.1 = BrakeDist {} {} {}
Step.1.Diag.0.Param3.0 = {} {} {} {}
Step.1.Diag.0.Param3.1 = {} {} {} {}
Step.1.Diag.0.Param3.2 = {} {} {} {}
Step.1.Var.0.Name = Variation 0
Step.1.Var.0.Param = 0.5
Step.1.Var.1.Name = Variation 1
Step.1.Var.1.Param = 0.7
Step.1.Var.2.Name = Variation 2
Step.1.Var.2.Param = 0.9
