// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "GameLiftUnrealAppGameMode.generated.h"

struct FProcessParameters;

DECLARE_LOG_CATEGORY_EXTERN(GameServerLog, Log, All);

UCLASS(minimalapi)
class AGameLiftUnrealAppGameMode : public AGameModeBase
{
	GENERATED_BODY()

public:
	AGameLiftUnrealAppGameMode();

protected:
    virtual void BeginPlay() override;
    virtual void PreLogin(const FString& Options, const FString& Address, const FUniqueNetIdRepl& UniqueId, FString& ErrorMessage) override;
    virtual APlayerController* Login(UPlayer* NewPlayer, ENetRole InRemoteRole, const FString& Portal, const FString& Options, const FUniqueNetIdRepl& UniqueId, FString& ErrorMessage) override;

private:
    void InitGameLift();
    bool IsGameSessionActive() const;
    bool ValidatePlayerSession(const FString& PlayerId) const;

private:
    TSharedPtr<FProcessParameters> ProcessParameters;

    bool bGameSessionActive = false;
    FString CurrentGameSessionId;
    TSet<FString> ValidPlayerIds;
};



