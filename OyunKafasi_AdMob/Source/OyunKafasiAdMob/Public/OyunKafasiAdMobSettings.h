#pragma once

#include "CoreMinimal.h"
#include "Engine/DeveloperSettings.h"
#include "OyunKafasiAdMobSettings.generated.h"

UCLASS(Config=Engine, DefaultConfig, meta=(DisplayName="OyunKafasi AdMob"))
class OYUNKAFASIADMOB_API UOyunKafasiAdMobSettings : public UDeveloperSettings
{
    GENERATED_BODY()

public:
    UOyunKafasiAdMobSettings();

    /** Your AdMob App ID, for example: ca-app-pub-XXXXXXXXXXXXXXXX~XXXXXXXXXX */
    UPROPERTY(EditAnywhere, Config, Category="AdMob", meta=(DisplayName="AdMob App ID"))
    FString AdMobAppId;

    // Banner Reklamlarý Ýçin ID Listesi
    UPROPERTY(Config, EditAnywhere, Category = "AdMob", meta = (DisplayName = "Banner Ad IDs"))
    TArray<FString> BannerAdIds;

    // Geçiþ (Interstitial) Reklamlarý Ýçin ID Listesi
    UPROPERTY(Config, EditAnywhere, Category = "AdMob", meta = (DisplayName = "Interstitial Ad IDs"))
    TArray<FString> InterstitialAdIds;

    virtual FName GetCategoryName() const override;
    virtual FName GetSectionName() const override;
};
