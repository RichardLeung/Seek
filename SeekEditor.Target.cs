// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class SeekEditorTarget : TargetRules
{
	public SeekEditorTarget(TargetInfo Target) : base(Target)
	{
		Type = TargetType.Editor;
		DefaultBuildSettings = BuildSettingsVersion.V4;
		IncludeOrderVersion = EngineIncludeOrderVersion.Unreal5_3;
		ExtraModuleNames.Add("Seek");
	}
}