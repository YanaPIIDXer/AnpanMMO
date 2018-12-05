// Fill out your copyright notice in the Description page of Project Settings.

using UnrealBuildTool;
using System.IO;

public class AnpanMMO : ModuleRules
{
	private string ThirdPartyPath
	{
		get { return Path.GetFullPath(Path.Combine(ModuleDirectory, "../../Source/ThirdParty/")); }
	}

	private string ScriptModulePath
	{
		get { return Path.GetFullPath(Path.Combine(ModuleDirectory, "../../Source/ScriptModule/")); }
	}

	public AnpanMMO(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;
	
		PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore", "Sockets", "Networking" , "Http", "PakFile"});

		PrivateDependencyModuleNames.AddRange(new string[] {  });

		// Uncomment if you are using Slate UI
		// PrivateDependencyModuleNames.AddRange(new string[] { "Slate", "SlateCore" });

		// Uncomment if you are using online features
		// PrivateDependencyModuleNames.Add("OnlineSubsystem");

		// To include OnlineSubsystemSteam, add it to the plugins section in your uproject file with the Enabled attribute set to true
		LoadLua(Target);
		LoadScriptModule(Target);
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

	private bool LoadScriptModule(ReadOnlyTargetRules Target)
	{
		string LibraryName = "libscriptmodule.a";
		switch (Target.Platform)
		{
			case UnrealTargetPlatform.Win64:

				LibraryName = "ScriptModule_x64.lib";
				break;

			case UnrealTargetPlatform.Win32:

				LibraryName = "ScriptModule_x86.lib";
				break;
		}

		string LibrariesPath = Path.Combine(ScriptModulePath, "Libraries");

		PublicAdditionalLibraries.Add(Path.Combine(LibrariesPath, LibraryName));

		PublicIncludePaths.Add(Path.Combine(ScriptModulePath, "Include"));
		
		return true;
	}
}
