// Fill out your copyright notice in the Description page of Project Settings.

#include "Widgets/UMG_Sample.h"
#include "Kismet/GameplayStatics.h"

void USampleWidgetCpp::NativePreConstruct()
{
	Super::NativePreConstruct();
}

void USampleWidgetCpp::NativeConstruct()
{
	Super::NativeConstruct();
}

void USampleWidgetCpp::NativeDestruct()
{
	Super::NativeDestruct();
}

void USampleWidgetCpp::NativeTick(const FGeometry& MyGeometry, float InDeltaTime)
{
	Super::NativeTick(MyGeometry, InDeltaTime);
}

TSharedRef<SWidget> USampleWidgetCpp::RebuildWidget()
{
	TSharedRef<SWidget> Widget = Super::RebuildWidget();

	UPanelWidget* RootWidget = Cast<UPanelWidget>(GetRootWidget());

	if (RootWidget && WidgetTree)
	{
		this->CanvasPanel = WidgetTree->ConstructWidget<UCanvasPanel>(UCanvasPanel::StaticClass(), FName(TEXT("")));
		RootWidget->AddChild(this->CanvasPanel);

		this->Text_Must = WidgetTree->ConstructWidget<UTextBlock>(UTextBlock::StaticClass(), FName(TEXT("Text Must")));
		this->CanvasPanel->AddChild(this->Text_Must);

		this->Text_Optional = WidgetTree->ConstructWidget<UTextBlock>(UTextBlock::StaticClass(), FName(TEXT("Text Optional")));
		this->CanvasPanel->AddChild(this->Text_Optional);
	}

	return Widget;
}