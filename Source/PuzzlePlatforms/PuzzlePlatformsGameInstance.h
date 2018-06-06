// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "OnlineSubsystem.h"

#include "MenuSystem/MenuInterface.h"
#include "PuzzlePlatformsGameInstance.generated.h"



/**
 * 
 */

class UUserWidget;
class UMenuWidget;

UCLASS()
class PUZZLEPLATFORMS_API UPuzzlePlatformsGameInstance : public UGameInstance,public IMenuInterface
{
	GENERATED_BODY()

public:
	UPuzzlePlatformsGameInstance(const FObjectInitializer & ObjectInitializer);

	virtual void Init();

	UFUNCTION(BlueprintCallable)//call by blueprint
	void LoadMenuWidget();

	UFUNCTION(BlueprintCallable)//call by blueprint
	void InGameLoadMenu();
	
	UFUNCTION(Exec)//call by console
	void Host() override;

	UFUNCTION(Exec)
	void Join(const FString& Address)override;

	virtual void LoadMainMenu() override;


private :

	TSubclassOf<UUserWidget> MenuClass;
	TSubclassOf<UUserWidget> InGameMenuClass;


	UMenuWidget *Menu;

	IOnlineSessionPtr SessionInterface;


	TSharedPtr<class FOnlineSessionSearch> SessionSearch;

	void OnCreateSessionComplete(FName SessionName, bool Success);
	void OnDestroySessionComplete(FName SessionName, bool Success);
	void CreateSession();
	void OnFindSessionsComplete(bool Success);





	
};
