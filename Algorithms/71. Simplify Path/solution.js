var simplifyPath = function (path) {
  const parts = path.split("/");
  const stack = [];

  for (let part of parts) {
    if (part === "" || part === ".") {
      continue;
    }
    if (part === "..") {
      if (stack.length > 0) {
        stack.pop();
      }
    } else {
      stack.push(part);
    }
  }

  return "/" + stack.join("/");
};
