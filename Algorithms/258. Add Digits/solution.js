var addDigits = function (num) {
  if (Math.floor(num / 10) === 0) {
    return num;
  }

  const numStr = `${num}`;
  num = 0;

  for (let i = 0; i < numStr.length; i++) {
    num += numStr[i] - "0";
  }

  return addDigits(num);
};
