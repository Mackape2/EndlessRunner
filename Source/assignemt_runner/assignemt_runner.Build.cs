// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class assignemt_runner : ModuleRules
{
	public assignemt_runner(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore", "HeadMountedDisplay", "EnhancedInput" });
	}
}
