/*
 * Copyright (c) Contributors to the Open 3D Engine Project.
 * For complete copyright and license terms please see the LICENSE at the root of this distribution.
 *
 * SPDX-License-Identifier: Apache-2.0 OR MIT
 *
 */

#pragma once

#include <TestImpactFramework/Native/TestImpactNativeConfiguration.h>

#include <TestImpactCommandLineOptions.h>

namespace TestImpact
{
    //! Representation of the command line options specific to the native runtime supplied to the console frontend application.
    class NativeCommandLineOptions
        : public CommandLineOptions
    {
    public:
        NativeCommandLineOptions(int argc, char** argv);

        //! Compiles the native command line usage to a string.
        static AZStd::string GetCommandLineUsageString();

        //! Returns the test sharding policy to use.
        Policy::TestSharding GetTestShardingPolicy() const;

        //! Returns the maximum number of test targets to be in flight at any given time.
        const AZStd::optional<size_t>& GetMaxConcurrency() const;

        //! Returns the individual test target timeout to use (if any).
        const AZStd::optional<AZStd::chrono::milliseconds>& GetTestTargetTimeout() const;

        //! Returns true if the safe mode option has been enabled, otherwise false.
        bool HasSafeMode() const;

    private:
        Policy::TestSharding m_testShardingPolicy = Policy::TestSharding::Never;
        AZStd::optional<size_t> m_maxConcurrency;
        AZStd::optional<AZStd::chrono::milliseconds> m_testTargetTimeout;
        bool m_safeMode = false;
    };
} // namespace TestImpact
