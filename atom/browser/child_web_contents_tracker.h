// Copyright (c) 2017 GitHub, Inc.
// Use of this source code is governed by the MIT license that can be
// found in the LICENSE file.

#ifndef ATOM_BROWSER_CHILD_WEB_CONTENTS_TRACKER_H_
#define ATOM_BROWSER_CHILD_WEB_CONTENTS_TRACKER_H_

#include <string>

#include "content/public/browser/web_contents_user_data.h"

namespace atom {

// ChildWebContentsTracker tracks child WebContents
// created by native `window.open()`
struct ChildWebContentsTracker
    : public content::WebContentsUserData<ChildWebContentsTracker> {
  GURL url;
  std::string frame_name;

 private:
  explicit ChildWebContentsTracker(content::WebContents* web_contents);
  friend class content::WebContentsUserData<ChildWebContentsTracker>;

  WEB_CONTENTS_USER_DATA_KEY_DECL();

  DISALLOW_COPY_AND_ASSIGN(ChildWebContentsTracker);
};

}  // namespace atom

#endif  // ATOM_BROWSER_CHILD_WEB_CONTENTS_TRACKER_H_
