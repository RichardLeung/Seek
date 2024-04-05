// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class SeekTarget : TargetRules
{
	public SeekTarget(TargetInfo Target) : base(Target)
	{
		Type = TargetType.Game;
		DefaultBuildSettings = BuildSettingsVersion.V4;
		IncludeOrderVersion = EngineIncludeOrderVersion.Unreal5_3;
		ExtraModuleNames.Add("Seek");
	}
}