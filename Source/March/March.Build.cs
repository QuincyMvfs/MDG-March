// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class March : ModuleRules
{
	public March(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[] {
			"Core",
			"CoreUObject",
			"Engine",
			"InputCore",
			"EnhancedInput",
			"AIModule",
			"StateTreeModule",
			"GameplayStateTreeModule",
			"UMG",
			"Slate"
		});

		PrivateDependencyModuleNames.AddRange(new string[] { });

		PublicIncludePaths.AddRange(new string[] {
			"March",
			"March/Variant_Platforming",
			"March/Variant_Platforming/Animation",
			"March/Variant_Combat",
			"March/Variant_Combat/AI",
			"March/Variant_Combat/Animation",
			"March/Variant_Combat/Gameplay",
			"March/Variant_Combat/Interfaces",
			"March/Variant_Combat/UI",
			"March/Variant_SideScrolling",
			"March/Variant_SideScrolling/AI",
			"March/Variant_SideScrolling/Gameplay",
			"March/Variant_SideScrolling/Interfaces",
			"March/Variant_SideScrolling/UI"
		});

		// Uncomment if you are using Slate UI
		// PrivateDependencyModuleNames.AddRange(new string[] { "Slate", "SlateCore" });

		// Uncomment if you are using online features
		// PrivateDependencyModuleNames.Add("OnlineSubsystem");

		// To include OnlineSubsystemSteam, add it to the plugins section in your uproject file with the Enabled attribute set to true
	}
}
