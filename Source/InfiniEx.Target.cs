// Copyright Abdulrahman Alhamoudi, 2016 - All rights reserved.

using UnrealBuildTool;
using System.Collections.Generic;

public class InfiniExTarget : TargetRules
{
	public InfiniExTarget(TargetInfo Target)
	{
		Type = TargetType.Game;
	}

	//
	// TargetRules interface.
	//

	public override void SetupBinaries(
		TargetInfo Target,
		ref List<UEBuildBinaryConfiguration> OutBuildBinaryConfigurations,
		ref List<string> OutExtraModuleNames
		)
	{
		OutExtraModuleNames.Add("InfiniEx");
	}
}
