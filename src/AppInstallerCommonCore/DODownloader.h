// Copyright (c) Microsoft Corporation.
// Licensed under the MIT License.
#pragma once
#include <AppInstallerDownloader.h>
#include <AppInstallerProgress.h>

#include <optional>
#include <ostream>
#include <string>
#include <vector>

namespace AppInstaller::Utility
{
    // Downloads a file from the given URL and places it in the given location.
    //   url: The url to be downloaded from. http->https redirection is allowed.
    //   dest: The stream to be downloaded to.
    //   computeHash: Optional. Indicates if SHA256 hash should be calculated when downloading.
    DownloadResult DODownload(
        const std::string& url,
        const std::filesystem::path& dest,
        IProgressCallback& progress,
        std::optional<DownloadInfo> info);

    // Returns true if the error from DODownload should be treated as fatal;
    // false if we should be able to fall back to other download methods.
    bool IsDOErrorFatal(HRESULT error);
}
