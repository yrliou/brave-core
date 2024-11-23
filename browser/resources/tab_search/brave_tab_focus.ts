// Copyright (c) 2024 The Brave Authors. All rights reserved.
// This Source Code Form is subject to the terms of the Mozilla Public
// License, v. 2.0. If a copy of the MPL was not distributed with this file,
// You can obtain one at https://mozilla.org/MPL/2.0/.

import 'chrome://resources/cr_elements/cr_button/cr_button.js';
import 'chrome://resources/cr_elements/cr_input/cr_input.js';

import { CrLitElement } from 'chrome://resources/lit/v3_0/lit.rollup.js';

export class BraveTabFocusElement extends CrLitElement {
  static get is() {
    return 'brave-tab-focus'
  }

  constructor() {
    super();

    this.visibilityChangedListener_ = () => {
      if (document.visibilityState === 'visible') {
        this.apiProxy_.getProfileDate().then({profileData} => {
          this.setTabs(profileData);
        }
      }
    }
  }

  private setTabs(profileData: ProfileData): void {
    this.tabs_ = profileData.windows.map((window) => {}
  }

  override render() {
    return getHtml.bind(this)();
  }
}

declare global {
  interface HTMLElementTagNameMap {
    'brave-tab-focus': BraveTabFocusElement;
  }
}

customElements.define(BraveTabFocusElement.is, BraveTabFocusElement);
