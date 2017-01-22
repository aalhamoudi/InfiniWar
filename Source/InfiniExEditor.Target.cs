// © Abdulrahman Alhamoudi, 2016 - All rights reserved

using UnrealBuildTool;
using System.Collections.Generic;

public class InfiniExEditorTarget : TargetRules
{
	public InfiniExEditorTarget(TargetInfo Target)
	{
		Type = TargetType.Editor;
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
