// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "ScoreController.generated.h"

UCLASS()
class PROTOTYPE_5TO_API AScoreController : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AScoreController();
	UPROPERTY(EditAnyWhere, BlueprintReadWrite, Category = "Widgets")
	TSubclassOf<class UUserWidget> ScoreTextWidget;
	TWeakObjectPtr<class UUserWidget> pScoreTextWidget;
	TWeakObjectPtr<class UTextBlock> pScoreText;
	TWeakObjectPtr<class UTextBlock> pShootsText;
	TWeakObjectPtr<class UTextBlock> pPullsText;

	// Exposed function to Blueprints
	UFUNCTION(BlueprintCallable, Category = "Score")
	void IncreaseScore(int amount);

	UFUNCTION(BlueprintCallable, Category = "Score")
	int GetScore() const;
	
	UFUNCTION(BlueprintCallable, Category = "Shoots")
	void DecreaseShoots(int amount);

	UFUNCTION(BlueprintCallable, Category = "Shoots")
	int GetShoots() const;

	UFUNCTION(BlueprintCallable, Category = "Pulls")
		void DecreasePulls(int amount);

	UFUNCTION(BlueprintCallable, Category = "Pulls")
		int GetPulls() const;

	UFUNCTION(BlueprintCallable, Category = "Shoots")
	void ResetShoots();
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	
private:
	int Score;
	int Shoots = 3;
	int Pulls = 5;
};
