// Copyright 2018 YanaPIIDXer All Rights Reserved.

#include "BlueprintCompileTest.h"
#include "AssetRegistryModule.h"
#include "Engine/Blueprint.h"
#include "Editor/Kismet/Public/BlueprintCompilationManager.h"
#include "Editor/UnrealEd/Public/Kismet2/CompilerResultsLog.h"
#include "Editor/UnrealEd/Public/Editor.h"

void FBlueprintCompileTest::GetTests(TArray<FString> &OutBeautifiedNames, TArray<FString> &OutTestCommands) const
{
	FAssetRegistryModule &AssetRegistryModule = FModuleManager::LoadModuleChecked<FAssetRegistryModule>("AssetRegistry");
	TArray<FAssetData> Assets;
	FARFilter Filter;
	Filter.ClassNames.Add("Blueprint");
	Filter.PackagePaths.Add("/Game");
	Filter.bRecursiveClasses = true;
	Filter.bRecursivePaths = true;
	AssetRegistryModule.Get().GetAssets(Filter, Assets);
	
	for (const auto &Asset : Assets)
	{
		OutBeautifiedNames.Add(Asset.AssetName.ToString());
		OutTestCommands.Add(Asset.PackagePath.ToString() + "/" + Asset.AssetName.ToString() + "." + Asset.AssetName.ToString());
	}
}

bool FBlueprintCompileTest::RunTest(const FString &Parameters)
{
	UBlueprint *pBP = LoadObject<UBlueprint>(GEditor->GetEditorWorldContext().World(), *Parameters, *Parameters);
	if (pBP == nullptr)
	{
		UE_LOG(LogTemp, Log, TEXT("%s Load Failed..."), *Parameters);
		return false;
	}
	
	FCompilerResultsLog Result;
	FBPCompileRequest Request(pBP, EBlueprintCompileOptions::BatchCompile, &Result);

	UE_LOG(LogTemp, Log, TEXT("Compiling %s..."), *Parameters);
	FBlueprintCompilationManager::CompileSynchronously(Request);

	return (Result.NumErrors == 0 && Result.NumWarnings == 0);
}
