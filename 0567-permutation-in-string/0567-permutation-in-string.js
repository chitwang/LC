/**
 * @param {string} s1
 * @param {string} s2
 * @return {boolean}
 */
var checkInclusion = function(str1, str2) {
    let v1 = new Array(26).fill(0);
		let v2 = new Array(26).fill(0);
		for(let i=0; i< str1.length; i++){
			v1[str1.charCodeAt(i) - "a".charCodeAt(0)]++;
		}
		for(let i=0; i< str2.length; i++){
			v2[str2.charCodeAt(i) - "a".charCodeAt(0)]++;
			if(i >= str1.length){
				v2[str2.charCodeAt(i - str1.length) - "a".charCodeAt(0)]--;
			}
			if(v1.toString() === v2.toString()){
				return true;
			}
		}
		return false;
};