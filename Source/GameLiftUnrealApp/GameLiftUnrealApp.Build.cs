// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class GameLiftUnrealApp : ModuleRules
{
	public GameLiftUnrealApp(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

    PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore", "EnhancedInput" });
    
    // Add the following section
    if (Target.Type == TargetType.Server)
    {
        PublicDependencyModuleNames.AddRange(new string[] { "GameLiftServerSDK", "GameLiftMetrics" });
    	PublicDefinitions.Add("WITH_GAMELIFT=1");
    }
    else
    {
      PublicDefinitions.Add("WITH_GAMELIFT=0");
    }
    bEnableExceptions =  true;
	}
}
