module Command = {
  let parse = text => {
    let separated =
      text |> String.contains(~substring="=")
        ? text |> String.split(~on="=") : [text];

    switch (separated) {
    | ["-g", name]
    | ["--greet", name] => `Greet(name)
    | ["-h"]
    | ["--help"] => `Help
    | _ => `Unknown
    };
  };

  let printify = command => {
    /* A JSX-like text-formatting library:
       https://reason-native.com/docs/pastel/ */
    Pastel.(
      switch (command) {
      | `Greet(name) =>
        <Pastel italic=true color=Green>
          "Hello "
          <Pastel underline=true color=Cyan> {name ++ "!"} </Pastel>
        </Pastel>
      | `Help =>
        <Pastel italic=true color=Green>
          "Try "
          <Pastel inverse=true> "--greet=<SomeName>" </Pastel>
        </Pastel>

      | `Unknown =>
        <Pastel color=Red>
          "Don't know that command. :-(\n\n"
          <Pastel color=Green> "Try: `--help`" </Pastel>
        </Pastel>
      }
    );
  };
};

let run = (~args) => {
  let commands =
    args
    |> Array.toList
    |> List.tail
    |> Option.withDefault(~default=[])
    |> List.map(~f=Command.parse);

  commands |> List.map(~f=Command.printify);
};
