// Fill out your copyright notice in the Description page of Project Settings.

using UnrealBuildTool;
using System.IO;

public class ScriptModule : ModuleRules
{
	private string ThirdPartyPath
	{
		get { return Path.GetFullPath(Path.Combine(ModuleDirectory, "../../Source/ThirdParty/")); }
	}

	public ScriptModule(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;
	
		PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine" });

		PrivateDependencyModuleNames.AddRange(new string[] {  });

		// Uncomment if you are using Slate UI
		// PrivateDependencyModuleNames.AddRange(new string[] { "Slate", "SlateCore" });

		// Uncomment if you are using online features
		// PrivateDependencyModuleNames.Add("OnlineSubsystem");

		// To include OnlineSubsystemSteam, add it to the plugins section in your uproject file with the Enabled attribute set to true
		LoadLua(Target);
	}

	private bool LoadLua(ReadOnlyTargetRules Target)
	{
		string PlatformString = ".a";
		switch (Target.Platform)
		{
			case UnrealTargetPlatform.Win64:

				PlatformString = ".x64.lib";
				break;

			case UnrealTargetPlatform.Win32:

				PlatformString = ".x86.lib";
				break;
		}

		string LibrariesPath = Path.Combine(ThirdPartyPath, "Lua", "libraries");

		PublicAdditionalLibraries.Add(Path.Combine(LibrariesPath, "Lua53" + PlatformString));

		PublicIncludePaths.Add(Path.Combine(ThirdPartyPath, "Lua", "includes"));

		PublicDefinitions.Add(string.Format("WITH_LUA_BINDING={0}", 1));

		return true;
	}


}