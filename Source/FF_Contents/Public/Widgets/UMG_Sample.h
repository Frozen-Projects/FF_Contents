// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Runtime/UMG/Public/UMG.h"

#include "Components/TextBlock.h"

#include "UMG_Sample.generated.h"

UCLASS()
class FF_CONTENTS_API USampleWidgetCpp : public UUserWidget
{
	GENERATED_BODY()
	
public:	

	virtual void NativePreConstruct() override;
	virtual void NativeConstruct() override;
	virtual void NativeDestruct() override;
	virtual void NativeTick(const FGeometry& MyGeometry, float InDeltaTime) override;
	virtual TSharedRef<SWidget> RebuildWidget() override;

	// You need to open "Show Inherited Variables" to show it in "Variables" section.

	UPROPERTY(BlueprintReadWrite, meta = (BindWidget))
	UCanvasPanel* CanvasPanel = nullptr;

	// "BindWidget" means, you have to add this widget in UMG blueprints.
	UPROPERTY(BlueprintReadWrite, Category = "Frozen Forest|Contents|Slice Widget", meta = (BindWidget))
	UTextBlock* Text_Must = nullptr;

	// "BindWidgetOptional" means, you don't have to add this widget in UMG blueprints.
	UPROPERTY(BlueprintReadWrite, Category = "Frozen Forest|Contents|Slice Widget", meta = (BindWidgetOptional))
	UTextBlock* Text_Optional = nullptr;

};