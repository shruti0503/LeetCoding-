/**
 * @param {string} word
 * @return {number}
 */
var numberOfSpecialChars = function(word) {
    const lower = new Set();
    const upper = new Set();

    for (let ch of word) {
        if (ch >= 'a' && ch <= 'z') {
            lower.add(ch);
        } else {
            upper.add(ch.toLowerCase());
        }
    }

    let count = 0;

    for (let ch of lower) {
        if (upper.has(ch)) {
            count++;
        }
    }

    return count;
};