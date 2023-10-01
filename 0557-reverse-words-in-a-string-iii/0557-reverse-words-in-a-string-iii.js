/**
 * @param {string} s
 * @return {string}
 */
function solve(str) {
	return str.split('').reverse().join('')
}
var reverseWords = function(s) {
    let words = s.split(' ');
    var reversed = [];
    for(let i=0; i<words.length; i++){
        reversed.push(solve(words[i]));
    }
    return reversed.join(' ');
};