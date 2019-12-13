# {{ project_slug }}

{{ project_desc }}

**Contains the following libraries and executables:**

```txt
{{ project_slug }}@0.0.0
│
├─test/
│   name:    Test{{ project_slug | camel_case }}.exe
│   main:    Test{{ project_slug | camel_case }}
│   require: {{ project_slug }}.lib
│
├─library/
│   library name: {{ project_slug }}.lib
│   namespace:    {{ project_slug | camel_case }}
│   require:
│
└─executable/
    name:    {{ project_slug | camel_case }}App.exe
    main:    {{ project_slug | camel_case }}App
    require: {{ project_slug }}.lib
```

## Developing

```bash
npm install -g esy
git clone <this-repo>
esy install
esy build
```

## Running Binary

After building the project, you can run the main binary that is produced.

```bash
esy x {{ project_slug | camel_case }}App.exe
```

## Running Tests

```bash
# Runs the "test" command in `package.json`.
esy test
```
