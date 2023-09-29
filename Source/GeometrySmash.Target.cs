// Geometry Smash. All Rights Reserved

using UnrealBuildTool;
using System.Collections.Generic;

public class GeometrySmashTarget : TargetRules
{
	public GeometrySmashTarget(TargetInfo Target) : base(Target)
	{
		Type = TargetType.Game;
		DefaultBuildSettings = BuildSettingsVersion.V2;

		ExtraModuleNames.AddRange( new string[] { "GeometrySmash" } );
	}
}
