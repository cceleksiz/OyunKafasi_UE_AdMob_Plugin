# OyunKafasi AdMob Plugin for Unreal Engine 5

A simple, open-source Unreal Engine plugin for integrating Google AdMob Interstitial Ads into Android projects.

The plugin uses UPL (Unreal Plugin Language) to inject the required Android Gradle dependency, AndroidManifest configuration, and native Java code during Unreal Engine's Android packaging process. This removes the need to manually edit generated Android Studio project files.

> **Current version:** Interstitial Ads only. Banner, Rewarded, App Open Ads, and Blueprint ad-event callbacks are planned for future versions.

## Features

- Quick Blueprint integration
- Automatic Google Mobile Ads SDK dependency injection
- Configurable AdMob App ID from Unreal Engine Project Settings
- Load and show Interstitial Ads from Blueprint
- Check whether an Interstitial Ad is ready
- Automatically load the next Interstitial Ad after the current ad is dismissed or fails to show
- No manual editing of generated Android Studio files

## Installation

1. Download or clone this repository.
2. In your Unreal Engine project root folder, create a `Plugins` folder if it does not already exist.
3. Place the `OyunKafasiAdMob` plugin folder inside the `Plugins` folder.
4. Restart your Unreal Engine project.
5. If Unreal Engine prompts you to rebuild missing modules, click **Yes**.
6. Go to `Edit -> Plugins` and make sure **OyunKafasi AdMob Plugin** is enabled.

  If your project is Blueprint-only:
   
7. Add an empty C++ class (in UE: _Tools -> New C++ Class..._). 
8. Right-click your `*.uproject` file and select _Generate Visual Studio project files_.

## Configuration

Before packaging your Android application:

1. Open `Edit -> Project Settings`.
2. Go to `Plugins -> OyunKafasi AdMob`.
3. Enter your **AdMob App ID**.

Example format:

`ca-app-pub-XXXXXXXXXXXXXXXX~XXXXXXXXXX`

If no App ID is configured, the plugin falls back to Google's official sample App ID. Do not use the sample ID for your production release.

## How to Use in Blueprint

### 1. Initialize and load an ad

At game startup, call:

`Init AdMob & Load Interstitial`

Pass your Interstitial Ad Unit ID.

Example:

`ca-app-pub-XXXXXXXXXXXXXXXX/XXXXXXXXXX`

A good place for this is `Game Instance`, `Game Mode`, or `Begin Play`.

### 2. Check whether the ad is ready

Before showing an ad, optionally call:

`Is Interstitial Ad Ready`

### 3. Show the ad

Call:

`Show Interstitial Ad`

The plugin automatically requests the next Interstitial Ad after the current one is dismissed or fails to display.

## Recommended Blueprint Flow

`Begin Play`
→ `Init AdMob & Load Interstitial`

When the player completes a level or dies:

`Is Interstitial Ad Ready`
→ If true: `Show Interstitial Ad`
→ If false: continue gameplay normally

## Requirements

- Unreal Engine 5.5 or higher
- Target Platform: Android
- A valid Google AdMob App ID
- A valid Interstitial Ad Unit ID

## Notes

This plugin currently focuses on Android Interstitial Ads. It does not yet provide Banner Ads, Rewarded Ads, App Open Ads, or Blueprint callbacks such as `OnAdLoaded` and `OnAdClosed`.

## Support & Developer

Developed by Oyun Kafası.

https://oyunkafasi.com.tr
