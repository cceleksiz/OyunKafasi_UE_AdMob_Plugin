#include "OyunKafasiAdMobSettings.h"

UOyunKafasiAdMobSettings::UOyunKafasiAdMobSettings()
{
    AdMobAppId = TEXT("ca-app-pub-3940256099942544~3347511713");
}

FName UOyunKafasiAdMobSettings::GetCategoryName() const
{
    return TEXT("Plugins");
}

FName UOyunKafasiAdMobSettings::GetSectionName() const
{
    return TEXT("OyunKafasi AdMob");
}
