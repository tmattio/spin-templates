let getAllUsers = () => {
  Accounts_user.(
    Result.return([{id: 0, name: "Tom"}, {id: 1, name: "John"}])
  );
};
