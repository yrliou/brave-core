/* Copyright (c) 2024 The Brave Authors. All rights reserved.
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this file,
 * You can obtain one at https://mozilla.org/MPL/2.0/. */

#ifndef BRAVE_COMPONENTS_AI_CHAT_CORE_BROWSER_LEO_LOCAL_MODELS_UPDATER_H_
#define BRAVE_COMPONENTS_AI_CHAT_CORE_BROWSER_LEO_LOCAL_MODELS_UPDATER_H_

#include <string>
#include <vector>

#include "base/no_destructor.h"
#include "components/component_updater/component_installer.h"

namespace component_updater {
class ComponentUpdateService;
}  // namespace component_updater

namespace ai_chat {

extern const char kUniversalQAModelName[];

class LeoLocalModelsComponentInstallerPolicy
    : public ::component_updater::ComponentInstallerPolicy {
 public:
  LeoLocalModelsComponentInstallerPolicy();
  LeoLocalModelsComponentInstallerPolicy(
      const LeoLocalModelsComponentInstallerPolicy&) = delete;
  LeoLocalModelsComponentInstallerPolicy& operator=(
      const LeoLocalModelsComponentInstallerPolicy&) = delete;
  ~LeoLocalModelsComponentInstallerPolicy() override;

  static void DeleteComponent();

  void ComponentReadyForTesting(const base::Version& version,
                                const base::FilePath& install_dir,
                                base::Value::Dict manifest);

 private:
  // ComponentInstallerPolicy::
  bool VerifyInstallation(const base::Value::Dict& manifest,
                          const base::FilePath& install_dir) const override;
  bool SupportsGroupPolicyEnabledComponentUpdates() const override;
  bool RequiresNetworkEncryption() const override;
  update_client::CrxInstaller::Result OnCustomInstall(
      const base::Value::Dict& manifest,
      const base::FilePath& install_dir) override;
  void OnCustomUninstall() override;
  void ComponentReady(const base::Version& version,
                      const base::FilePath& install_dir,
                      base::Value::Dict manifest) override;
  base::FilePath GetRelativeInstallDir() const override;
  void GetHash(std::vector<uint8_t>* hash) const override;
  std::string GetName() const override;
  update_client::InstallerAttributes GetInstallerAttributes() const override;
  bool IsBraveComponent() const override;
};

class LeoLocalModelsUpdaterState {
 public:
  static LeoLocalModelsUpdaterState* GetInstance();

  LeoLocalModelsUpdaterState(const LeoLocalModelsUpdaterState&) = delete;
  LeoLocalModelsUpdaterState& operator=(const LeoLocalModelsUpdaterState&) =
      delete;

  void SetInstallDir(const base::FilePath& install_dir);
  const base::FilePath& GetInstallDir() const;

  const base::FilePath& GetUniversalQAModel() const;

 private:
  friend base::NoDestructor<LeoLocalModelsUpdaterState>;
  LeoLocalModelsUpdaterState();
  ~LeoLocalModelsUpdaterState();

  base::FilePath install_dir_;
  base::FilePath universal_qa_model_path_;
};

void ManageLeoLocalModelsComponentRegistration(
    component_updater::ComponentUpdateService* cus);

}  // namespace ai_chat

#endif  // BRAVE_COMPONENTS_AI_CHAT_CORE_BROWSER_LEO_LOCAL_MODELS_UPDATER_H_
