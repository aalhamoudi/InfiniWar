// © Abdulrahman Alhamoudi, 2016 - All rights reserved

using UnrealBuildTool;

public class InfiniEx : ModuleRules
{
	public InfiniEx(TargetInfo Target)
	{
		PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore", "HeadMountedDisplay" });
	}
}
