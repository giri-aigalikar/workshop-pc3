setenv('MSYS_ROOT' , 'MSYS-2020')
addpath(genpath('C:/Users/ipg-pc/Desktop/DemoPipeline/JenkinsTest/src'));
load_system('JenkinAcc');
set_param('JenkinAcc','LaunchReport','off');
try
	rtwbuild('JenkinAcc');
catch
	warning('Error while building Model1');
% 	exit(1);
end
save_system('JenkinAcc');
close_system('JenkinAcc');
