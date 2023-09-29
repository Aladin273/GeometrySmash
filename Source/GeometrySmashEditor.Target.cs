// Geometry Smash. All Rights Reserved

using UnrealBuildTool;
using System.Collections.Generic;

public class GeometrySmashEditorTarget : TargetRules
{
	public GeometrySmashEditorTarget(TargetInfo Target) : base(Target)
	{
		Type = TargetType.Editor;
		DefaultBuildSettings = BuildSettingsVersion.V2;

		ExtraModuleNames.AddRange( new string[] { "GeometrySmash" } );
	}
}
