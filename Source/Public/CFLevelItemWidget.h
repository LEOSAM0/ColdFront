// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "CFCoreTypes.h"
#include "CFLevelItemWidget.generated.h"

class UButton;
class UTextBlock;
class UImage;

UCLASS()
class CF_API UCFLevelItemWidget : public UUserWidget
{
	GENERATED_BODY()

public:
	FOnLevelSelectedSignature OnLevelSelected;

	void SetLevelData(const FLevelData& Data);
	FLevelData GetLevelData() const { return LevelData; }

	void SetSelected(bool IsSelected);
	
protected:
	UPROPERTY(meta = (BindWidget))
		UButton* LevelSelectButton;

	UPROPERTY(meta = (BindWidget))
		UTextBlock* LevelNameTextBlock;

	UPROPERTY(meta = (BindWidget))
		UImage* LevelImage = nullptr;

	UPROPERTY(meta = (BindWidget))
		UImage* FrameImage;

	virtual void NativeOnInitialized() override;

private:
	FLevelData LevelData;

	UFUNCTION()
		void OnLevelItemClicked();

	UFUNCTION()
		void OnLevelHovered();

	UFUNCTION()
		void OnLevelUnhovered();
};
