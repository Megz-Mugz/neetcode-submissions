class Solution:

    def encode(self, words: List[str]) -> str:
        encoded_str = ""
        for word in words:
            encoded_str += f"{len(word)}#{word}"
        return encoded_str

    def decode(self, encoded_str: str) -> List[str]:
        decoded_words = []

        while encoded_str:
            stop = encoded_str.index('#')
            len_of_word = int(encoded_str[0:stop])
            decoded_words.append(encoded_str[stop+1: stop + len_of_word+1])
            encoded_str = encoded_str[stop + int(len_of_word) + 1:]
            
        return decoded_words
