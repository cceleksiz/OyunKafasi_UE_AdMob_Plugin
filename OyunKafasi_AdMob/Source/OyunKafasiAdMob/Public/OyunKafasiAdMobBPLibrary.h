#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "OyunKafasiAdMobBPLibrary.generated.h"

UCLASS()
class OYUNKAFASIADMOB_API UOyunKafasiAdMobBPLibrary : public UBlueprintFunctionLibrary
{
    GENERATED_BODY()

public:
    /** Initializes Google Mobile Ads once and loads an Interstitial Ad using the supplied Ad Unit ID. */
    UFUNCTION(BlueprintCallable, Category="OyunKafasi Ads|Interstitial", meta=(DisplayName="Init AdMob & Load Interstitial"))
    static void InitAdMob(FString AdUnitID);

    /** Returns true when an Interstitial Ad is loaded and ready to be shown. */
    UFUNCTION(BlueprintPure, Category="OyunKafasi Ads|Interstitial", meta=(DisplayName="Is Interstitial Ad Ready"))
    static bool IsInterstitialAdReady();

    /** Shows the loaded Interstitial Ad. The plugin automatically loads the next ad after dismissal or a show failure. */
    UFUNCTION(BlueprintCallable, Category="OyunKafasi Ads|Interstitial", meta=(DisplayName="Show Interstitial Ad"))
    static void ShowInterstitialAd();
};
