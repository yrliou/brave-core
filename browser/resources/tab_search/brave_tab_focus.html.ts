// Copyright (c) 2024 The Brave Authors. All rights reserved.
// This Source Code Form is subject to the terms of the Mozilla Public
// License, v. 2.0. If a copy of the MPL was not distributed with this file,
// You can obtain one at https://mozilla.org/MPL/2.0/.

import { html } from '//resources/lit/v3_0/lit.rollup.js';
import type { BraveTabFocusElement } from './brave_tab_focus.js';

export function getHtml(this: BraveTabFocusElement) {
  return html`<!--_html_template_start_-->
    <div id="brave-tab-focus" class="brave-tab-focus">
        <div class="title">Focus tabs</div>
        <div class="subtitle">Gather all related tabs into a new window to help you focus on a specific topic</div>
        <cr-input id="topic-input" class="topic-input" placeholder="Enter a topic to focus on..." type=text" .value="${this.topic}">
          <cr-button class="action-button" @click="${this.onFocusTabsClick}">Go</cr-button>
        </cr-input>
        <cr-button class="action-buton" @click="${this.onSuggestTopicsClick}">Suggest Topics</cr-button>
    </div>
    <!--_html_template_end_-->`;
}
