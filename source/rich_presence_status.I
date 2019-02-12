 /**
 * Author: Jordan Maxwell
 * Written: 02/11/2019
 *
 * The MIT License (MIT)
 * 
 * Copyright (c) 2019 Nxt Games
 * 
 * Permission is hereby granted, free of charge, to any person obtaining a copy of
 * this software and associated documentation files (the "Software"), to deal in
 * the Software without restriction, including without limitation the rights to
 * use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies
 * of the Software, and to permit persons to whom the Software is furnished to do
 * so, subject to the following conditions:
 * 
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 * 
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 */

INLINE void RichPresenceStatus::set_state(const std::string state) {
    this->state = state;
}

INLINE std::string RichPresenceStatus::get_state() {
    return this->state;
}

INLINE void RichPresenceStatus::set_details(const std::string details) {
    this->details = details;
}

INLINE std::string RichPresenceStatus::get_details() {
    return this->details;
}

INLINE void RichPresenceStatus::set_start_timestamp(int64_t startTimestamp) {
    this->startTimestamp = startTimestamp;
}

INLINE int64_t RichPresenceStatus::get_start_timestamp() {
    return this->startTimestamp;
}

INLINE void RichPresenceStatus::set_end_timestamp(int64_t endTimestamp) {
    this->endTimestamp = endTimestamp;
}

INLINE int64_t RichPresenceStatus::get_end_timestamp() {
    return this->endTimestamp;
}

INLINE void RichPresenceStatus::set_large_image_key(const std::string largeImageKey) {
    this->largeImageKey = largeImageKey;
}

INLINE std::string RichPresenceStatus::get_large_image_key() {
    return this->largeImageKey;
}

INLINE void RichPresenceStatus::set_large_image_text(const std::string largeImageText) {
    this->largeImageText = largeImageText;
}

INLINE std::string RichPresenceStatus::get_large_image_text() {
    return this->largeImageText;
}

INLINE void RichPresenceStatus::set_small_image_key(const std::string smallImageKey) {
    this->smallImageKey = smallImageKey;
}

INLINE std::string RichPresenceStatus::get_small_image_key() {
    return this->smallImageKey;
}

INLINE void RichPresenceStatus::set_small_image_text(const std::string smallImageText) {
    this->smallImageText = smallImageText;
}

INLINE std::string RichPresenceStatus::get_small_image_text() {
    return this->smallImageText;
}

INLINE void RichPresenceStatus::set_party_id(const std::string partyId) {
    this->partyId = partyId;
}

INLINE std::string RichPresenceStatus::get_party_id() {
    return this->partyId;
}

INLINE void RichPresenceStatus::set_party_size(int partySize) {
    this->partySize = partySize;
}

INLINE int RichPresenceStatus::get_party_size() {
    return this->partySize;
}

INLINE void RichPresenceStatus::set_party_max(int partyMax) {
    this->partyMax = partyMax;
}

INLINE int RichPresenceStatus::get_party_max() {
    return this->partyMax;
}

INLINE void RichPresenceStatus::set_match_secret(const std::string matchSecret) {
    this->matchSecret = matchSecret;
}

INLINE std::string RichPresenceStatus::get_match_secret() {
    return this->matchSecret;
}

INLINE void RichPresenceStatus::set_join_secret(const std::string joinSecret) {
    this->joinSecret = joinSecret;
}

INLINE std::string RichPresenceStatus::get_join_secret() {
    return this->joinSecret;
}

INLINE void RichPresenceStatus::set_spectate_secret(const std::string spectateSecret) {
    this->spectateSecret = spectateSecret;
}

INLINE std::string RichPresenceStatus::get_spectate_secret() {
    return this->spectateSecret;
}

INLINE void RichPresenceStatus::set_instance(int8_t instance) {
    this->instance = instance;
}

INLINE int8_t RichPresenceStatus::get_instance() {
    return this->instance;
}